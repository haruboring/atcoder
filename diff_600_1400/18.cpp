#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int N, M;
vector<vector<int>> G(2000 + 100, vector<int>(0));
vector<vector<int>> dist(2000 + 100, vector<int>(2000 + 100, 1e9));

void dfs(int i, int pos, int ex_pos, int d) {
    dist[i][pos] = d;
    for (auto next : G[pos]) {
        if (d + 1 < dist[i][next]) dfs(i, next, pos, d + 1);
    }
}

int main() {
    cin >> N >> M;
    vector<int> u(M), v(M);
    rep(i, M) cin >> u[i] >> v[i];

    rep(i, M) G[u[i]].push_back(v[i]);

    repp(i, 1, N + 1) {
        dfs(i, i, -1, 0);
    }

    int ans = 0;
    repp(i, 1, N + 1) {
        repp(j, 1, N + 1) {
            if (dist[i][j] != 1e9 && dist[i][j] >= 2) ans++;
        }
    }

    cout << ans << endl;
}