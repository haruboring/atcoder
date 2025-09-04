#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(K);
    rep(i, K) cin >> A[i];

    vector<bool> dp(N + 1, false);
    rep(i, N + 1) {
        bool ok = false;
        rep(j, K) {
            if (i - A[j] >= 0 && dp[i - A[j]] == false) dp[i] = true, ok = true;
        }
        if (!ok) dp[i] = false;
    }

    if (dp[N]) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
}
