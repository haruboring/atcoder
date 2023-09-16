#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int H, W, R, C;
    cin >> H >> W >> R >> C;
    int ans = 4;
    if (R == 1) {
        ans--;
    }
    if (R == H) {
        ans--;
    }
    if (C == 1) {
        ans--;
    }
    if (C == W) {
        ans--;
    }
    cout << ans << endl;
}