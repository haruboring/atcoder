#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    vector<int> x(4), y(4);
    rep(i, 4) {
        cin >> x[i] >> y[i];
    }
    bool is_totsu = true;

    if (((y[0] - y[2]) * (x[1] - x[2]) - (x[0] - x[2]) * (y[1] - y[2])) *
            ((y[0] - y[2]) * (x[3] - x[2]) - (x[0] - x[2]) * (y[3] - y[2])) >
        0) {
        is_totsu = false;
    }

    if (((y[1] - y[3]) * (x[0] - x[3]) - (x[1] - x[3]) * (y[0] - y[3])) *
            ((y[1] - y[3]) * (x[2] - x[3]) - (x[1] - x[3]) * (y[2] - y[3])) >
        0) {
        is_totsu = false;
    }

    if (is_totsu) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}