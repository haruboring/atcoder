#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int T;
    cin >> T;

    rep(_, T) {
        int N, M;
        cin >> N >> M;
        vector<int> C(N);
        rep(i, N) cin >> C[i];
        vector<int> u(M), v(M);
        rep(i, M) cin >> u[i] >> v[i];
        rep(i, M) u[i]--, v[i]--;

        vector<vector<int>> G(N);
        rep(i, M) {
            G[u[i]].push_back(v[i]);
            G[v[i]].push_back(u[i]);
        }

        vector<vector<int>> dp(N, vector<int>(N, 1e18));
        dp[0][N - 1] = 0;
        queue<pair<int, int>> q;
        q.push({0, N - 1});
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (auto ni : G[i]) {
                for (auto nj : G[j]) {
                    if (C[ni] != C[nj] && dp[ni][nj] == 1e18) {
                        dp[ni][nj] = dp[i][j] + 1;
                        q.push({ni, nj});
                    }
                }
            }
        }

        int ans = dp[N - 1][0];
        if (ans == 1e18) ans = -1;
        cout << ans << endl;
    }
}
