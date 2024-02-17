#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M;
    cin >> N >> M;
    vector<int> u(M), v(M);
    rep(i, M) cin >> u[i] >> v[i];
    vector<int> W(N);
    rep(i, N) cin >> W[i];
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    rep(i, M) {
        u[i]--, v[i]--;
    }
    vector<vector<int>> G(N);
    rep(i, M) {
        G[u[i]].push_back(v[i]);
        G[v[i]].push_back(u[i]);
    }

    vector<pair<int, int>> p(N);
    rep(i, N) {
        p[i] = {W[i], i};
    }
    sort(all(p));

    vector<int> power(N, 0);
    rep(tmi, N) {
        auto [w, i] = p[tmi];
        // 計算量の概算ミスってた、解説
        vector<vector<int>> dp(G[i].size() + 1, vector<int>(W[i], 0));
        dp[0][0] = 1;
        rep(j, G[i].size()) {
            rep(k, W[i]) {
                if (dp[j][k] == 0) continue;
                dp[j + 1][k] = max(dp[j + 1][k], dp[j][k]);
                if (k + W[G[i][j]] < W[i]) {
                    dp[j + 1][k + W[G[i][j]]] = max(dp[j + 1][k + W[G[i][j]]], dp[j][k] + power[G[i][j]]);
                }
            }
        }
        power[i] = *max_element(all(dp[G[i].size()]));
    }

    int ans = 0;
    rep(i, N) {
        ans += power[i] * A[i];
    }
    cout << ans << endl;
}
