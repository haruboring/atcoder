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

    vector<int> dp1(N + 1, 0);
    repp(i, 1, N + 1) {
        if (A[i - 1] >= dp1[i - 1] + 1) {
            dp1[i] = dp1[i - 1] + 1;
        } else {
            dp1[i] = min(A[i - 1], dp1[i - 1]);
        }
    }

    vector<int> dp2(N + 1, 0);
    for (int i = N - 1; i >= 0; i--) {
        if (A[i] >= dp2[i + 1] + 1) {
            dp2[i] = dp2[i + 1] + 1;
        } else {
            dp2[i] = min(A[i], dp2[i + 1]);
        }
    }

    int ans = 0;
    rep(i, N) {
        ans = max(ans, min(dp1[i + 1], dp2[i]));
    }

    cout << ans << endl;
}
