#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int H, W, K;
    cin >> H >> W >> K;
    vector<string> S(H);
    rep(i, H) cin >> S[i];

    vector<vector<tuple<int, int, int>>> G1(H, vector<tuple<int, int, int>>(W)), G2(H, vector<tuple<int, int, int>>(W));

    rep(i, H) {
        rep(j, W) {
            if (j != 0) G1[i][j] = G1[i][j - 1];
            if (S[i][j] == 'o') {
                get<0>(G1[i][j])++;
            } else if (S[i][j] == 'x') {
                get<1>(G1[i][j])++;
            } else {
                get<2>(G1[i][j])++;
            }
        }
    }

    rep(j, W) {
        rep(i, H) {
            if (i != 0) G2[i][j] = G2[i - 1][j];
            if (S[i][j] == 'o') {
                get<0>(G2[i][j])++;
            } else if (S[i][j] == 'x') {
                get<1>(G2[i][j])++;
            } else {
                get<2>(G2[i][j])++;
            }
        }
    }

    int ans = 1e9;

    rep(i, H) {
        rep(j, W - K + 1) {
            auto [co, cx, c] = G1[i][j + K - 1];
            if (j != 0) {
                co -= get<0>(G1[i][j - 1]);
                cx -= get<1>(G1[i][j - 1]);
                c -= get<2>(G1[i][j - 1]);
            }

            if (cx != 0) continue;
            ans = min(ans, c);
        }
    }

    rep(j, W) {
        rep(i, H - K + 1) {
            auto [co, cx, c] = G2[i + K - 1][j];

            // cout << i << " " << j << " " << co << " " << cx << " " << c << endl;
            if (i != 0) {
                co -= get<0>(G2[i - 1][j]);
                cx -= get<1>(G2[i - 1][j]);
                c -= get<2>(G2[i - 1][j]);
            }

            if (cx != 0) continue;
            ans = min(ans, c);
        }
    }

    if (ans == 1e9) ans = -1;

    cout << ans << endl;
}
