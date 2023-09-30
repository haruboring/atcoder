#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, K, P;
    cin >> N >> K >> P;
    vector<int> C(N);
    vector<vector<int>> A(N, vector<int>(K));
    rep(i, N) {
        cin >> C[i];
        rep(j, K) cin >> A[i][j];
    }

    vector<vector<int>> dp(N + 1, vector<int>((6 * 6 * 6 * 6 * 6 + 1), 1e18));

    dp[0][0] = 0;

    rep(i, N) {
        rep(j, pow(P + 1, K) + 1) {
            if (dp[i][j] == 1e18) continue;

            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);

            string str_j_P = "";

            int tmp = j;
            rep(k, K) {
                str_j_P += to_string(tmp % (P + 1));
                tmp /= P + 1;
            }
            reverse(all(str_j_P));

            // cout << "i = " << i << ", j = " << str_j_P << ", str_j_P = " << str_j_P << endl;
            string new_j_P = "";
            rep(k, K) {
                new_j_P += to_string(min(str_j_P[k] - '0' + A[i][k], P));
            }

            // cout << "i = " << i << ", j = " << str_j_P << ", new_j_P = " << new_j_P << endl;

            int new_j = 0;
            int tmp2 = 1;
            rep(k, K) {
                new_j += (new_j_P[K - 1 - k] - '0') * tmp2;
                tmp2 *= P + 1;
            }

            dp[i + 1][new_j] = min(dp[i + 1][new_j], dp[i][j] + C[i]);
        }
    }

    if (dp[N][pow(P + 1, K) - 1] == 1e18)
        cout << -1 << endl;
    else
        cout << dp[N][pow(P + 1, K) - 1] << endl;

    return 0;
}