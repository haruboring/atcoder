#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int A, X, M;
    cin >> A >> X >> M;

    int ans = 0;
    int tmp = 1;
    rep(i, min(1000000LL, X)) {
        ans += tmp;
        ans %= M;
        tmp *= A;
        tmp %= M;
    }

    int i = min(1000000LL, X);
    int base = tmp;
    int base_ans = ans;
    while (i < X) {
        if (i + 1000000LL > X) {
            for (int j = 0; j < X - i; j++) {
                ans += tmp;
                ans %= M;
                tmp *= A;
                tmp %= M;
            }
            i = X;
        } else {
            ans += base_ans * tmp;
            ans %= M;
            tmp *= base;
            tmp %= M;
            i += 1000000LL;
        }
    }

    cout << ans << endl;
}