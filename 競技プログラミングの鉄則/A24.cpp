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
    vector<int> A(N), dp(N), L(N, 5000000 + 100);
    rep(i, N) {
        cin >> A[i];
    }
    L[0] = 0;
    int max_len = -1;
    rep(i, N) {
        dp[i] = lower_bound(L.begin(), L.end(), A[i]) - L.begin();
        L[dp[i]] = min(L[dp[i]], A[i]);
        max_len = max(max_len, dp[i]);
    }

    cout << max_len << endl;
}