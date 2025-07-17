#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    string S;
    cin >> S;

    int r, m;
    rep(i, 3) {
        if (S[i] == 'R') r = i;
        if (S[i] == 'M') m = i;
    }

    if (r < m) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
