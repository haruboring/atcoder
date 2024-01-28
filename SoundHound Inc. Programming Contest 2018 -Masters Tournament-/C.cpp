#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int n, m, d;
    cin >> n >> m >> d;

    double k = -1;
    if (d == 0) {
        k = 1 / (double)n;
    } else {
        k = (double)(n - d) * 2.0 / (double)(n * n);
    }

    cout << fixed << setprecision(10) << k * (m - 1) << endl;
}