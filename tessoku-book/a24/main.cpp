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
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    vector<int> dp(N, 1e18);
    rep(i, N) {
        int idx = lower_bound(all(dp), A[i]) - dp.begin();
        dp[idx] = A[i];
    }

    for (int i = N - 1; i >= 0; i--) {
        if (dp[i] != 1e18) {
            cout << i + 1 << endl;
            return 0;
        }
    }
}
