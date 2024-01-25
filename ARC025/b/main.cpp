#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> c(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> c[i][j];

    rep(i, H) {
        rep(j, W) {
            int black = 0, white = 0;
            rep(k, H-i)
        }
    }
}
