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
    vector<string> S(H);
    rep(i, H) cin >> S[i];

    int a = 1e9, b = -1, c = 1e9, d = -1;
    rep(i, H) rep(j, W) {
        if (S[i][j] == '#') {
            a = min(a, i);
            b = max(b, i);
            c = min(c, j);
            d = max(d, j);
        }
    }

    rep(i, H) {
        rep(j, W) {
            if (i < a || b < i || j < c || d < j) continue;
            if (S[i][j] == '.') {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
}
