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
    vector<int> A(N);
    rep(i, N) {
        cin >> A[i];
    }
    vector<vector<bool>> dp(N + 1, vector<bool>(N * 10000 + 10));
    rep(i, N + 1) {
        rep(j, N * 10000 + 10) {
            dp[i][j] = false;
        }
    }
    dp[0][0] = true;
    repp(i, 1, N + 1) {
        rep(j, N * 10000 + 10) {
            if (dp[i - 1][j] == true) {
                dp[i][j] = true;
                dp[i][j + A[i - 1]] = true;
            }
        }
    }
    if (dp[N][S]) {
        vector<int> ans(0);
        int pos = S;
        rep(i, N) {
            if (pos - A[N - 1 - i] >= 0 && dp[N - 1 - i][pos - A[N - 1 - i]]) {
                ans.push_back(N - i);
                pos -= A[N - 1 - i];
            }
        }
        sort(all(ans));
        cout << ans.size() << endl;
        rep(i, ans.size()) {
            cout << ans[i] << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
}