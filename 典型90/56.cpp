#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, S;
    cin >> N >> S;
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    vector<vector<bool>> dp(N + 1, vector<bool>(S + 1, false));
    dp[0][0] = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < S; j++) {
            if (dp[i][j] == false) continue;
            if (j + A[i] <= S) {
                dp[i + 1][j + A[i]] = true;
            }
            if (j + B[i] <= S) {
                dp[i + 1][j + B[i]] = true;
            }
        }
    }

    if (!dp[N][S]) {
        cout << "Impossible" << endl;
        return 0;
    }

    int cost = S;
    string ans = "";
    for (int i = N - 1; i >= 0; i--) {
        if (cost - A[i] >= 0 && dp[i][cost - A[i]]) {
            ans += "A";
            cost -= A[i];
        } else {
            ans += "B";
            cost -= B[i];
        }
    }
    reverse(all(ans));

    cout << ans << endl;
}
