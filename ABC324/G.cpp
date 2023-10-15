#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

vector<vector<tuple<int, int, int>>> graph(2 * 1e5 + 100);
vector<bool> visited(2 * 1e5 + 100, false);
double ans = 0.0;

void dfs(int v, int dest, double beauty, double cost) {
    if (v == dest) {
        double ratio = beauty / cost;
        ans = max(ans, ratio);
        return;
    }

    visited[v] = true;

    for (auto [u, b, c] : graph[v]) {
        if (!visited[u]) {
            dfs(u, dest, beauty + b, cost + c);
        }
    }

    visited[v] = false;
}

signed main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int u, v, b, c;
        cin >> u >> v >> b >> c;
        graph[v].push_back({u, b, c});
    }

    dfs(N, 1, 0, 0);

    cout << fixed << setprecision(20) << ans << endl;

    return 0;
}
