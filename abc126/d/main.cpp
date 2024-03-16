#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

void dfs(int v, int pv, vector<vector<int>> &G, map<pair<int, int>, int> &d, vector<int> &color) {
    for (auto nv : G[v]) {
        if (nv == pv) continue;
        int dist = d[{v, nv}];
        if (dist % 2 == 0) {
            color[nv] = color[v];
        } else {
            color[nv] = -color[v];
        }

        dfs(nv, v, G, d, color);
    }
}

signed main() {
    int N;
    cin >> N;
    vector<int> u(N - 1), v(N - 1), w(N - 1);
    rep(i, N - 1) cin >> u[i] >> v[i] >> w[i];

    vector<vector<int>> G(N, vector<int>(0));
    rep(i, N - 1) {
        G[u[i] - 1].push_back(v[i] - 1);
        G[v[i] - 1].push_back(u[i] - 1);
    }
    map<pair<int, int>, int> d;
    rep(i, N - 1) {
        d[{u[i] - 1, v[i] - 1}] = w[i];
        d[{v[i] - 1, u[i] - 1}] = w[i];
    }

    vector<int> color(N, 0);
    color[0] = 1;
    dfs(0, -1, G, d, color);

    rep(i, N) {
        if (color[i] == -1) color[i] = 0;
        cout << color[i] << endl;
    }
}
