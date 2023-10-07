#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int Xa, Ya, Xb, Yb, Xc, Yc;
    cin >> Xa >> Ya >> Xb >> Yb >> Xc >> Yc;

    int dx = 0, dy = 0;
    if (Xb < Xc) {
        dx = -1;
    } else if (Xb > Xc) {
        dx = 1;
    }
    if (Yb < Yc) {
        dy = -1;
    } else if (Yb > Yc) {
        dy = 1;
    }

    int X = Xb + dx, Y = Yb;
    int ans1 = abs(X - Xa) + abs(Y - Ya);
    if (Xa == X && (Y - Ya) * (Y - Yb) > 0) ans1 += 2;
    if (Ya == Y && (X - Xa) * (X - Xb) > 0) ans1 += 2;
    ans1 += abs(Xb - Xc) + abs(Yb - Yc);
    if (abs(Xb - Xc) > 0 && abs(Yb - Yc) > 0) ans1 += 2;
    if (X == Xb && Y == Yb) ans1 = 1e18;

    X = Xb, Y = Yb + dy;
    int ans2 = abs(X - Xa) + abs(Y - Ya);
    if (Xa == X && (Y - Ya) * (Y - Yb) > 0) ans2 += 2;
    if (Ya == Y && (X - Xa) * (X - Xb) > 0) ans2 += 2;
    ans2 += abs(Xb - Xc) + abs(Yb - Yc);
    if (abs(Xb - Xc) > 0 && abs(Yb - Yc) > 0) ans2 += 2;
    if (X == Xb && Y == Yb) ans2 = 1e18;

    debug(ans1);
    debug(ans2);

    cout << min(ans1, ans2) << endl;
}