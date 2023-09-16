#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int T;
    cin >> T;
    rep(i, T) {
        ll a, s;
        cin >> a >> s;
        bool b = false;
        if (s - 2 * a >= 0) {
            if (((s - 2 * a) & a) == 0) {
                b = true;
            }
        }
        if (b) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}