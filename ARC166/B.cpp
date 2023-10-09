#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, a, b, c;
    cin >> N >> a >> b >> c;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    vector<int> abc = {a, b, c};

    vector<vector<int>> dp(N + 1, vector<int>(1 << 3, 1e18));
    dp[0][0] = 0;

    rep(i, N) {
        int x = A[i];
        int a = 1;
        rep(j, 1 << 3) {
            if (dp[i][j] == 1e18) continue;
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            bitset<3> bs1(j);

            repp(k, 1, 1 << 3) {
                bitset<3> bs2(k);

                int tmp = -1;
                rep(l, 3) {
                    if (bs2[l] == 1) {
                        if (tmp == -1)
                            tmp = abc[l];
                        else
                            tmp = lcm(tmp, abc[l]);
                    }
                }

                // debug(tmp);

                if (x % tmp == 0) {
                    dp[i + 1][j | k] = min(dp[i + 1][j | k], dp[i][j] + 0);
                } else {
                    dp[i + 1][j | k] = min(dp[i + 1][j | k], dp[i][j] + (x / tmp + 1) * tmp - x);
                }
            }
        }
    }

    cout << dp[N][7] << endl;
}
