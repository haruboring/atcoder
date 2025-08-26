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
    rep(i, N) cin >> A[i];

    vector<vector<bool>> dp(N + 1, vector<bool>(S + 1, false));
    dp[0][0] = true;
    rep(i, N) {
        rep(j, S + 1) {
            if (dp[i][j] == false) continue;
            dp[i + 1][j] = true;
            if (j + A[i] > S) continue;
            dp[i + 1][j + A[i]] = true;
        }
    }
    if (dp[N][S]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
