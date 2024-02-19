#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

void dfs(int v, vector<vector<int>> &G, vector<bool> &visited, vector<pair<int, int>> &edges) {
    visited[v] = true;
    for (int nv : G[v]) {
        if (visited[nv]) continue;
        edges.push_back({v, nv});
        dfs(nv, G, visited, edges);
    }
}

signed main() {
    int N, M;
    cin >> N >> M;
    vector<int> U(M), V(M);
    rep(i, M) cin >> U[i] >> V[i];

    vector<vector<int>> G(N);
    rep(i, M) {
        U[i]--;
        V[i]--;
        G[U[i]].push_back(V[i]);
        G[V[i]].push_back(U[i]);
    }

    vector<pair<int, int>> t1_edges, t2_edges;

    vector<bool> visited(N, false);
    dfs(0, G, visited, t1_edges);

    fill(all(visited), false);
    queue<pair<int, int>> q;
    q.push({0, -1});
    visited[0] = true;
    while (!q.empty()) {
        auto [v, prev] = q.front();
        q.pop();
        for (int nv : G[v]) {
            if (visited[nv]) continue;
            visited[nv] = true;
            q.push({nv, v});
            t2_edges.push_back({v, nv});
        }
    }

    for (auto [u, v] : t1_edges) {
        cout << u + 1 << " " << v + 1 << endl;
    }
    for (auto [u, v] : t2_edges) {
        cout << u + 1 << " " << v + 1 << endl;
    }
}
