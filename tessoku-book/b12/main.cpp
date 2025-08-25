#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N;
    cin >> N;

    double l = 0, r = 1e4;
    rep(_, 64) {
        double x = (l + r) / 2;
        double a = x * x * x + x;
        if (a > N) {
            r = x;
        } else {
            l = x;
        }
    }

    cout << fixed << setprecision(10) << r << endl;
}
