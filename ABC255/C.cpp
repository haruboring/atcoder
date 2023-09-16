#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    ll X, A, D, N;
    cin >> X >> A >> D >> N;
    ll ans;
    if (D == 0) {
        cout << abs(X - A) << endl;
        return 0;
    }
    if (((X - A) / D) <= 0) {
        ans = abs(X - A);
    } else if (((X - A) / D) >= N - 1) {
        ans = abs(X - (A + D * (N - 1)));
    } else {
        ans = abs(X - (A + D * ((X - A) / D)));
    }
    if (((X - A) / D + 1) <= 0) {
        ans = min(ans, abs(X - A));
    } else if (((X - A) / D + 1) >= N - 1) {
        ans = min(ans, abs(X - (A + D * (N - 1))));
    } else {
        ans = min(ans, abs(X - (A + D + D * ((X - A) / D))));
    }
    if (((X - A) / D - 1) <= 0) {
        ans = min(ans, abs(X - A));
    } else if (((X - A) / D - 1) >= N - 1) {
        ans = min(ans, abs(X - (A + D * (N - 1))));
    } else {
        ans = min(ans, abs(X - (A - D + D * ((X - A) / D))));
    }
    cout << ans << endl;
}