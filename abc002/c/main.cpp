#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    double xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    double a = sqrt(pow(xa - xb, 2) + pow(ya - yb, 2));
    double b = sqrt(pow(xb - xc, 2) + pow(yb - yc, 2));
    double c = sqrt(pow(xa - xc, 2) + pow(ya - yc, 2));
    double s = (a + b + c) / 2;
    cout << fixed << setprecision(10) << sqrt(s * (s - a) * (s - b) * (s - c)) << endl;
}
