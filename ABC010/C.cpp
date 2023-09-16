#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int xa, ya, xb, yb, T, V, n;
    cin >> xa >> ya >> xb >> yb >> T >> V >> n;
    vector<int> x(n), y(n);
    rep(i, n) {
        cin >> x[i] >> y[i];
    }
    rep(i, n) {
        double dis = 0;
        dis += sqrt(pow(x[i] - xa, 2) + pow(y[i] - ya, 2));
        dis += sqrt(pow(x[i] - xb, 2) + pow(y[i] - yb, 2));
        if (dis <= T * V) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}