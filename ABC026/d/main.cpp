#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int A, B, C;
    cin >> A >> B >> C;

    double l = 0, r = 300;
    while (r - l > 1e-12) {
        double mid = (l + r) / 2;
        if (A * mid + B * sin(C * mid * M_PI) < 100) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << fixed << setprecision(15) << r << endl;
}
