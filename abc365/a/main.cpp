#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int Y;
    cin >> Y;

    if (Y % 4 != 0) {
        cout << 365 << endl;
        return 0;
    }
    if (Y % 400 == 0) {
        cout << 366 << endl;
        return 0;
    }
    if (Y % 100 == 0) {
        cout << 365 << endl;
        return 0;
    }
    cout << 366 << endl;
}
