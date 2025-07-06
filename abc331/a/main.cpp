#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int M, D, y, m, d;
    cin >> M >> D >> y >> m >> d;

    if (d == D) {
        if (m == M) {
            cout << y + 1 << " " << 1 << " " << 1 << endl;
        } else {
            cout << y << " " << m + 1 << " " << 1 << endl;
        }
    } else {
        cout << y << " " << m << " " << d + 1 << endl;
    }
}
