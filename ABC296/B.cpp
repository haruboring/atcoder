#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    vector<string> S(8);
    rep(i, 8) {
        cin >> S[i];
    }
    rep(i, 8) {
        rep(j, 8) {
            if (S[i][j] == '*') {
                cout << char('a' + j) << 8 - i << endl;
                return 0;
            }
        }
    }
}