#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    vector<vector<char>> c(4, vector<char>(4));
    rep(i, 4) {
        rep(j, 4) {
            cin >> c[i][j];
        }
    }
    rep(i, 4) {
        rep(j, 4) {
            cout << c[3-i][3-j] << " ";
        }
        cout << endl;
    }
}