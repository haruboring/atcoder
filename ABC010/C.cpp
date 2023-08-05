#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
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