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
pair<int, int> min_e() { return {0, 0}; }

vector<pair<int, int>> depth(200000 + 100);
map<pair<int, int>, int> weight;
vector<int> dist(0);
vector<pair<int, int>> dept(0);
map<pair<int, int>, vector<int>> edge2idx;
map<int, vector<int>> top2idx;
vector<bool> visited(200000);
int idx = 0;
void dfs(int v, int p, vector<vector<int>> &G) {
    dist.push_back(weight[{v, p}]);
    dept.push_back({depth[v].first, v});
    edge2idx[{min(v, p), max(v, p)}].push_back(idx);
    top2idx[v].push_back(idx);
    idx++;
    visited[v] = true;

    for (auto nv : G[v]) {
        if (visited[nv]) continue;
        dfs(nv, v, G);
    }

    dist.push_back(-weight[{v, p}]);
    dept.push_back({depth[v].first, v});
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

    depth[0] = {0, 0};
    vector<bool> visited(N);
    visited[0] = true;
    queue<int> que;
    que.push(0);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (auto nv : G[v]) {
            if (visited[nv]) continue;
            depth[nv].first = depth[v].first + 1;
            depth[nv].second = nv;
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
            int i1 = top2idx[x[i] - 1][0];
            int i2 = top2idx[y[i] - 1][0];
            if (i1 > i2) swap(i1, i2);

            auto [dep, pa] = seg_dept.prod(i1, i2 + 1);

            int ans = seg_dist.prod(0, i1 + 1) + seg_dist.prod(0, i2 + 1) - 2 * seg_dist.prod(0, top2idx[pa][0] + 1);
            cout << ans << endl;
        }
    }
}
