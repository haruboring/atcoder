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
    rep(_, T) {
        int x, y, z;
        cin >> x >> y >> z;

        x -= (y + 1) / 2;
        if (x < 0) {
            cout << "No" << endl;
            continue;
        }
        if (y % 2 == 1 && z == 0) {
            cout << "No" << endl;
            continue;
        }
        if (z > ((y + 1) / 2 + x)) {
            cout << "No" << endl;
            continue;
        }

        cout << "Yes" << endl;
    }
}
