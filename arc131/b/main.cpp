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
    vector<string> C(H);
    rep(i, H) cin >> C[i];

    rep(i, H) rep(j, W) {
        if (C[i][j] == '.') {
            set<char> s;
            if (i > 0) s.insert(C[i - 1][j]);
            if (i < H - 1) s.insert(C[i + 1][j]);
            if (j > 0) s.insert(C[i][j - 1]);
            if (j < W - 1) s.insert(C[i][j + 1]);

            for (char c = '1'; c <= '5'; c++) {
                if (!s.count(c)) {
                    C[i][j] = c;
                    break;
                }
            }
        }
    }
    rep(i, H) cout << C[i] << endl;
}
