#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int sumop(int a, int b) { return a + b; }
int sum_e() { return 0; }
pair<int, int> min_op(pair<int, int> a, pair<int, int> b) { return min(a, b); }
pair<int, int> min_e() { return {1e9, 1e9}; }

map<int, int> depth;
map<pair<int, int>, int> weight;
vector<int> dist(0);
vector<pair<int, int>> dept(0);
map<pair<int, int>, vector<int>> edge2idx;
map<int, vector<int>> top2idx, top2idx1;
vector<bool> visited(200000);
int idx = 0, idx1 = 0;
void dfs(int v, int p, vector<vector<int>> &G) {
    dist.push_back(weight[{v, p}]);
    edge2idx[{min(v, p), max(v, p)}].push_back(idx);
    top2idx[v].push_back(idx);
    visited[v] = true;
    idx++;

    for (auto nv : G[v]) {
        dept.push_back({depth[v], v});
        top2idx1[v].push_back(idx1);
        idx1++;
        if (visited[nv]) continue;
        dfs(nv, v, G);
        dept.push_back({depth[v], v});
        top2idx1[v].push_back(idx1);
        idx1++;
    }

    dist.push_back(-weight[{v, p}]);
    edge2idx[{min(v, p), max(v, p)}].push_back(idx);
    top2idx[v].push_back(idx);
    idx++;
}

signed main() {
    int N;
    cin >> N;
    vector<int> u(N - 1), v(N - 1), w(N - 1);
    rep(i, N - 1) cin >> u[i] >> v[i] >> w[i];
    int Q;
    cin >> Q;
    vector<int> flag(Q), x(Q), y(Q);
    rep(i, Q) cin >> flag[i] >> x[i] >> y[i];

    vector<vector<int>> G(N);
    rep(i, N - 1) {
        G[u[i] - 1].push_back(v[i] - 1);
        G[v[i] - 1].push_back(u[i] - 1);
    }

    rep(i, N - 1) {
        weight[{u[i] - 1, v[i] - 1}] = w[i];
        weight[{v[i] - 1, u[i] - 1}] = w[i];
    }
    rep(i, N) weight[{i, i}] = 0;

    depth[0] = 0;
    vector<bool> visited(N);
    visited[0] = true;
    queue<int> que;
    que.push(0);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (auto nv : G[v]) {
            if (visited[nv]) continue;
            depth[nv] = depth[v] + 1;
            visited[nv] = true;
            que.push(nv);
        }
    }

    dfs(0, 0, G);

    atcoder::segtree<int, sumop, sum_e> seg_dist(dist);
    atcoder::segtree<pair<int, int>, min_op, min_e> seg_dept(dept);
    rep(i, Q) {
        if (flag[i] == 1) {
            vector<int> idxs = edge2idx[{min(u[x[i] - 1] - 1, v[x[i] - 1] - 1), max(u[x[i] - 1] - 1, v[x[i] - 1] - 1)}];
            seg_dist.set(idxs[0], y[i]);
            seg_dist.set(idxs[1], -y[i]);
        } else {
            if (N == 1) {
                cout << 0 << endl;
                continue;
            }
            int i1 = top2idx[x[i] - 1][0];
            int i2 = top2idx[y[i] - 1][0];
            if (i1 > i2) swap(i1, i2);

            int i11 = top2idx1[x[i] - 1][0];
            int i21 = top2idx1[y[i] - 1][0];

            if (i11 > i21) swap(i11, i21);

            auto [dep, pa] = seg_dept.prod(i11, i21 + 1);

            int ans = seg_dist.prod(0, i1 + 1) + seg_dist.prod(0, i2 + 1) - 2 * seg_dist.prod(0, top2idx[pa][0] + 1);
            cout << ans << endl;
        }
    }
}
/*
8
1 2 105
1 3 103
2 4 105
2 5 100
5 6 101
3 7 106
3 8 100
1
2 5 5
*/