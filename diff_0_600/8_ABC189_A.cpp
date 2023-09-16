#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    string C;
    cin >> C;
    bool b = true;
    rep(i, 2) {
        if (C[i] != C[i + 1]) {
            b = false;
        }
    }
    if (b) {
        cout << "Won" << endl;
    } else {
        cout << "Lost" << endl;
    }
}