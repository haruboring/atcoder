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
    vector<vector<int>> X(H, vector<int>(W));
    rep(i, H) {
        rep(j, W) {
            cin >> X[i][j];
        }
    }
    int Q;
    cin >> Q;
    vector<vector<int>> ABCD(Q, vector<int>(4));
    rep(i, Q) {
        cin >> ABCD[i][0] >> ABCD[i][1] >> ABCD[i][2] >> ABCD[i][3];
    }
    vector<vector<int>> cnt(H + 1, vector<int>(W + 1));
    rep(i, H + 1) {
        rep(j, W + 1) {
            if (i * j == 0) {
                cnt[i][j] = 0;
            } else {
                cnt[i][j] += (X[i - 1][j - 1] + cnt[i][j - 1]);
            }
        }
    }
    rep(i, H + 1) {
        rep(j, W + 1) {
            if (i * j == 0) {
                cnt[i][j] = 0;
            } else {
                cnt[i][j] += cnt[i - 1][j];
            }
        }
    }
    rep(i, Q) {
        cout << cnt[ABCD[i][2]][ABCD[i][3]] - cnt[ABCD[i][2]][ABCD[i][1] - 1] - cnt[ABCD[i][0] - 1][ABCD[i][3]] + cnt[ABCD[i][0] - 1][ABCD[i][1] - 1] << endl;
    }
}