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

    vector<int> cX, cY;
    cX.push_back(X), cY.push_back(Y);
    while (X > 1 || Y > 1) {
        if (X > Y) {
            X -= Y;
        } else {
            Y -= X;
        }
        cX.push_back(X), cY.push_back(Y);
    }

    cout << cX.size() - 1 << endl;
    rep(i, cX.size() - 1) cout << cX[cX.size() - 2 - i] << " " << cY[cY.size() - 2 - i] << endl;
}
