#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int X, Y, Z;
    cin >> X >> Y >> Z;
    int can_pass = -1;
    if (X * Y < 0) {
        can_pass = abs(X);
    } else if (abs(X) < abs(Y)) {
        can_pass = abs(X);
    } else if (Y > 0 && Y > Z) {
        can_pass = abs(Z) + abs(X - Z);
    } else if (Y < 0 && Y < Z) {
        can_pass = abs(Z) + abs(X - Z);
    } else {
        can_pass = -1;
    }

    cout << can_pass << endl;
}