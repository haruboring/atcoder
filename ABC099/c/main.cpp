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

    set<int> st;
    rep(i, 20) {
        if (pow(6, i) > N) break;
        st.insert(pow(6, i));
    }
    rep(i, 20) {
        if (pow(9, i) > N) break;
        st.insert(pow(9, i));
    }

    vector<int> dp(N + 1, 1e9);
    dp[0] = 0;
    rep(i, N) {
        for (auto x : st) {
            if (i + x > N) continue;
            dp[i + x] = min(dp[i + x], dp[i] + 1);
        }
    }
    cout << dp[N] << endl;
}
