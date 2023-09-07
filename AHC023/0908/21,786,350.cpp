#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int T, K, H, W, i0;
vector<int> S, D;
vector<vector<bool>> h, v;

random_device rd;
mt19937 engine(rd());
uniform_int_distribution<int> dist_W(0, 20 - 1), dist_H(0, 20 - 1);

void read_input() {
    cin >> T >> H >> W >> i0;
    h.resize(H - 1, vector(W, false));
    for (int i = 0; i < H - 1; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < W; ++j)
            if (s[j] == '1') h[i][j] = true;
    }
    v.resize(H, vector(W - 1, false));
    for (int i = 0; i < H; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < W - 1; ++j)
            if (s[j] == '1') v[i][j] = true;
    }
    cin >> K;
    S.resize(K);
    D.resize(K);
    for (int i = 0; i < K; ++i) cin >> S[i] >> D[i];
}

struct Work {
    int k, i, j, s;
};

bool reachable(int i, int j, const vector<vector<vector<pair<int, int>>>> &adj, const vector<vector<bool>> &used) {
    if (used[i][j] || used[i0][0]) {
        return false;
    } else if (i == i0 && j == 0) {
        return true;
    }
    queue<pair<int, int>> q;
    q.emplace(i0, 0);
    vector visited(H, vector(W, false));
    visited[i0][0] = true;
    while (!q.empty()) {
        const auto [i1, j1] = q.front();
        q.pop();
        for (const auto &[i2, j2] : adj[i1][j1]) {
            if (i2 == i && j2 == j) {
                return true;
            } else if (!used[i2][j2] && !visited[i2][j2]) {
                visited[i2][j2] = true;
                q.emplace(i2, j2);
            }
        }
    }

    return false;
}

bool is_valid_plan(const vector<Work> &plan, const vector<vector<vector<pair<int, int>>>> &adj) {
    vector<vector<Work>> plant_list(T + 1), harvest_list(T + 1);
    for (const Work &w : plan) {
        plant_list[w.s].push_back(w);
        harvest_list[D[w.k]].push_back(w);
    }

    vector used(H, vector(W, false));
    for (int t = 1; t <= T; ++t) {
        // planting phase
        for (const Work &w : plant_list[t]) {
            if (!reachable(w.i, w.j, adj, used)) {
                return false;
            }
        }
        for (const Work &w : plant_list[t]) {
            if (used[w.i][w.j]) {
                return false;
            } else {
                used[w.i][w.j] = true;
            }
        }

        // harvesting phase
        for (const Work &w : harvest_list[t]) {
            used[w.i][w.j] = false;
        }
        for (const Work &w : harvest_list[t]) {
            if (!reachable(w.i, w.j, adj, used)) {
                return false;
            }
        }
    }

    return true;
}

signed main() {
    read_input();
    // Tは100
    // H = W = 20
    // 0 <= i0 <= H - 1
    // 0 < K <= HWT, 40000 = 4*10^4
    // 1 <= S[k] < D[k] <= T

    // construct a graph
    vector adj(H, vector(W, vector<pair<int, int>>()));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i + 1 < H && !h[i][j]) {
                // no waterway between (i, j) and (i + 1, j)
                adj[i][j].emplace_back(i + 1, j);
                adj[i + 1][j].emplace_back(i, j);
            }
            if (j + 1 < W && !v[i][j]) {
                // no waterway between (i, j) and (i, j + 1)
                adj[i][j].emplace_back(i, j + 1);
                adj[i][j + 1].emplace_back(i, j);
            }
        }
    }

    vector<Work> plan;

    // 最速で詰めまくる。
    vector<vector<int>> dist(H, vector<int>(W, 1e9));
    dist[i0][0] = 0;
    queue<pair<int, int>> q;
    q.emplace(i0, 0);
    while (!q.empty()) {
        const auto [i, j] = q.front();
        q.pop();
        for (const auto &[i2, j2] : adj[i][j]) {
            if (i2 < 0 || i2 >= H || j2 < 0 || j2 >= W) continue;
            if (dist[i2][j2] > dist[i][j] + 1) {
                dist[i2][j2] = dist[i][j] + 1;
                q.emplace(i2, j2);
            }
        }
    }

    vector<tuple<int, int, int>> dist_i_j(H * W);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) dist_i_j[i * W + j] = {dist[i][j], i, j};
    }
    sort(all(dist_i_j));
    reverse(all(dist_i_j));

    vector<tuple<int, int, int>> DSK(K);
    for (int i = 0; i < K; i++) {
        DSK[i] = {D[i], S[i], i};
    }
    sort(all(DSK));

    int cnt = 0;
    int std = 0;

    // 植えれるだけ植える。(n期作)
    set<int> planted;

    vector<tuple<int, int>> tmp(0);
    int tmp_d;
    for (int i = 0; i < K; i++) {
        auto [d, s, k] = DSK[i];
        if (cnt >= H * W || i == K - 1) {
            cnt = 0;
            std = tmp_d;
            if (i != K - 1) i--;

            // 回収が遅い順に植えたい。
            reverse(all(tmp));
            for (int j = 0; j < tmp.size(); j++) {
                auto [k, s] = tmp[j];
                int i1 = get<1>(dist_i_j[j]);
                int j1 = get<2>(dist_i_j[j]);
                plan.push_back({k, i1, j1, s});
                cnt++;
            }
            tmp.clear();
            continue;
        }
        if (s > std) {
            tmp_d = d;
            auto [dis, ii, jj] = dist_i_j[cnt];
            tmp.push_back({k, std + 1});
            cnt++;
        }
    }

    sort(all(plan), [](const Work &a, const Work &b) { return a.k < b.k; });
    // write output
    cout << plan.size() << '\n';
    for (const Work &w : plan) {
        cout << w.k + 1 << ' ' << w.i << ' ' << w.j << ' ' << w.s << '\n';
    }
}

/*
min(K, 10)としていたので、ここを拡張して
min(K, 500)とした. スコアは約50倍になった.
実行時間が1765msだからもうこれ以上は無理そう

ただし、元は一ループごとにHW回（400回）回していたので、
今回はランダムに10回実施して、それがうまく時のみ採用するようにした。

とりあえずこの100というハイパラを修正してこの手法の限界を探るのが今日の目標
あと、ローカルの実行環境を構築する

今後の手法として、
- 有効かどうかのチェックに対する計算量の削減
    - Kは40000までなので、チェックの計算量を減らせればそれなりのスコアは出せそう
- そもそも配置のためのアルゴリズムを変える
    - おそらく上の手法だと、チェックの計算量はO(N)ぐらいになりそう。これだとKが上限近い時に上手くいかない
    - なので配置のアルゴリズムを工夫するという手もある
- 現状植える時期を考慮していないので、これを工夫する

の3つがある。

早く植えれば植えるほど良いの知らんかった。→変わらん。
*/