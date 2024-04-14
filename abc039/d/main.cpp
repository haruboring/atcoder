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

    vector<vector<char>> ans(H, vector<char>(W, '.'));
    rep(i, H) {
        rep(j, W) {
            bool ok = true;
            if (S[i][j] == '.') ok = false;
            if (i > 0 && S[i - 1][j] == '.') ok = false;
            if (i < H - 1 && S[i + 1][j] == '.') ok = false;
            if (j > 0 && S[i][j - 1] == '.') ok = false;
            if (j < W - 1 && S[i][j + 1] == '.') ok = false;
            if (j > 0 && i > 0 && S[i - 1][j - 1] == '.') ok = false;
            if (j < W - 1 && i > 0 && S[i - 1][j + 1] == '.') ok = false;
            if (j > 0 && i < H - 1 && S[i + 1][j - 1] == '.') ok = false;
            if (j < W - 1 && i < H - 1 && S[i + 1][j + 1] == '.') ok = false;
            if (ok) ans[i][j] = '#';
        }
    }

    vector<vector<char>> S2(H, vector<char>(W, '.'));
    rep(i, H) {
        rep(j, W) {
            if (ans[i][j] == '.') continue;
            S2[i][j] = '#';
            if (i > 0) S2[i - 1][j] = '#';
            if (i < H - 1) S2[i + 1][j] = '#';
            if (j > 0) S2[i][j - 1] = '#';
            if (j < W - 1) S2[i][j + 1] = '#';
            if (j > 0 && i > 0) S2[i - 1][j - 1] = '#';
            if (j < W - 1 && i > 0) S2[i - 1][j + 1] = '#';
            if (j > 0 && i < H - 1) S2[i + 1][j - 1] = '#';
            if (j < W - 1 && i < H - 1) S2[i + 1][j + 1] = '#';
        }
    }

    rep(i, H) {
        rep(j, W) {
            if (S[i][j] != S2[i][j]) {
                cout << "impossible" << endl;
                return 0;
            }
        }
    }

    cout << "possible" << endl;
    rep(i, H) {
        rep(j, W) {
            cout << ans[i][j];
        }
        cout << endl;
    }
}
