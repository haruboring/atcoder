#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N;
    cin >> N;

    string nN = to_string(N);
    int n = nN.size();
    rep(i, 15 - n) nN = "0" + nN;

    int ans = 0;
    repp(s, 1, 14 * 9 + 2) {
        vector<vector<vector<vector<int>>>> dp(16, vector<vector<vector<int>>>(15 * 10, vector<vector<int>>(15 * 10, vector<int>(2, 0))));
        dp[0][0][0][0] = 1;
        rep(i, 15) {
            int std = nN[i] - '0';
            rep(k, s + 1) {
                // とりうる桁の総和
                rep(l, s) {
                    // kに対応するあまり
                    // 未満が1
                    rep(d, std) {
                        dp[i + 1][k + d][(10 * l + d) % s][1] += dp[i][k][l][0];
                    }
                    dp[i + 1][k + std][(10 * l + std) % s][0] += dp[i][k][l][0];

                    rep(d, 10) {
                        dp[i + 1][k + d][(10 * l + d) % s][1] += dp[i][k][l][1];
                    }
                }
            }
        }
        ans += dp[15][s][0][0] + dp[15][s][0][1];
    }

    cout << ans << endl;
}
