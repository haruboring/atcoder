#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int x, y;
    cin >> x >> y;

    if (x == y) {
        cout << x << endl;
    } else {
        rep(i, 3) {
            if (i == x) continue;
            if (i == y) continue;
            cout << i << endl;
        }
    }
}
