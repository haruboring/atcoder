#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    int g, h, i, j, k, l;
    cin >> g >> h >> i >> j >> k >> l;
    if (max(a, g) < min(d, j) && max(b, h) < min(e, k) && max(c, i) < min(f, l)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
