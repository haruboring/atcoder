#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    int la = (xa - xb) * (xa - xb) + (ya - yb) * (ya - yb);
    int lb = (xb - xc) * (xb - xc) + (yb - yc) * (yb - yc);
    int lc = (xc - xa) * (xc - xa) + (yc - ya) * (yc - ya);

    debug(la);
    debug(lb);
    debug(lc);

    if (la == lb + lc || lb == la + lc || lc == la + lb) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
