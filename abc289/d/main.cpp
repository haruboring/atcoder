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
    int M;
    cin >> M;
    vector<int> B(M);
    rep(i, M) cin >> B[i];
    int X;
    cin >> X;

    set<int> mochi;
    rep(i, M) mochi.insert(B[i]);

    vector<bool> dp(X + 1, false);
    dp[0] = true;
    rep(i, X) {
        if (dp[i] == false) continue;
        if (mochi.count(i)) continue;
        rep(j, N) {
            if (i + A[j] > X) continue;
            dp[A[j] + i] = true;
        }
    }
    if (dp[X]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
