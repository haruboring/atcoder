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
    if (x == 2 || y == 2) {
        cout << "No" << endl;
        return 0;
    }
    if (x > 7) x++;
    if (y > 7) y++;
    if (x % 2 == y % 2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
