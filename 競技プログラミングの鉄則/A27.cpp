#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    ll A, B;
    cin >> A >> B;
    ll ans = 0;
    repp(i, 1, sqrt(A) + 1) {
        if (A % i == 0) {
            if (B % i == 0) {
                ans = max(ans, (ll)i);
            }
            if (B % (A / i) == 0) {
                ans = max(ans, A / i);
            }
        }
    }
    cout << ans << endl;
}