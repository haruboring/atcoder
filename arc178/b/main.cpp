#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using mint = atcoder::modint998244353;

signed main() {
    int T;
    cin >> T;

    rep(_, T) {
        int a1, a2, a3;
        cin >> a1 >> a2 >> a3;

        if (a1 > a2) swap(a1, a2);
        if (a3 < a2 || a3 > a2 + 1) {
            cout << 0 << endl;
            continue;
        }
        mint ten = 10;
        if (a1 == a2 && a2 == a3) {
            mint t = ten.pow(a1) - 2 * ten.pow(a1 - 1);
            mint cnt = t * (t + 1) / 2;
            cout << cnt.val() << endl;
        } else if (a1 == a2 && a2 < a3) {
            mint t1 = ten.pow(a1) - ten.pow(a1 - 1);
            mint cnt = (ten.pow(a1) - 1) * (ten.pow(a1) - 2 * ten.pow(a1 - 1)) / 2 + t1 * ten.pow(a1 - 1);
            cout << cnt.val() << endl;
        } else if (a1 < a2 && a2 == a3) {
            mint t1 = ten.pow(a1) - ten.pow(a1 - 1);
            mint t2 = ten.pow(a2) - ten.pow(a2 - 1) - ten.pow(a1);
            mint cnt = t1 * t2 + t1 * (t1 + 1) / 2;
            cout << cnt.val() << endl;
        } else if (a1 < a2 && a2 < a3) {
            mint t1 = ten.pow(a1) - ten.pow(a1 - 1);
            mint cnt = ten.pow(a1 - 1) * t1 + t1 * (t1 - 1) / 2;
            cout << cnt.val() << endl;
        }
    }
}
