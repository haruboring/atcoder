#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using modint = atcoder::modint998244353;

signed main() {
    int N;
    cin >> N;
    vector<vector<int>> AB(N, vector<int>(2));
    rep(i, N) cin >> AB[i][0] >> AB[i][1];

    vector<vector<modint>> dp(N, vector<modint>(2));
    dp[0][0] = 1, dp[0][1] = 1;
    rep(i, N - 1) {
        rep(j, 2) {
            rep(k, 2) {
                if (AB[i + 1][k] != AB[i][j]) {
                    dp[i + 1][k] += dp[i][j];
                }
            }
        }
    }
    cout << (dp[N - 1][0] + dp[N - 1][1]).val() << endl;

    // rep(i, N) {
    //     rep(j, 2) {
    //         cerr << dp[i][j] << " ";
    //     }
    //     cerr << endl;
    // }
}