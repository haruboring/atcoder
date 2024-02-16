#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int X, Y;
    cin >> X >> Y;

    bool sswap = false;
    if (X == 0) {
        sswap = true;
        swap(X, Y);
    }

    bool x_reversed = false;
    if (X < 0) {
        x_reversed = true;
        X = -X;
    }
    bool y_reversed = false;
    if (Y < 0) {
        y_reversed = true;
        Y = -Y;
    }

    if (gcd(X + 2, Y) == 1) {
        cout << -1 << endl;
        return 0;
    }

    int s = (X + 2) / gcd(X + 2, Y) * Y;
    s /= Y;
    int t = double(Y) / X * s - (double)2 / X;

    if (sswap) swap(s, t);
    if (x_reversed) s = -s;
    if (y_reversed) t = -t;
    cout << s << " " << t << endl;
}
