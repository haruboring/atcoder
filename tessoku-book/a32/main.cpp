#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, A, B;
    cin >> N >> A >> B;

    vector<bool> dp(N + 1, false);
    rep(i, N + 1) {
        if (i >= A && dp[i - A] == false) {
            dp[i] = true;
        } else if (i >= B && dp[i - B] == false) {
            dp[i] = true;
        } else {
            dp[i] = false;
        }
    }

    if (dp[N]) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
}
