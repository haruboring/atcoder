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
    vector<vector<int>> A(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];
    vector<int> P(H + W - 1);
    rep(i, H + W - 1) cin >> P[i];

    vector<vector<int>> d(H, vector<int>(W, 0));
    d[0][0] = A[0][0] - P[0];
    int ans = 1e9;
    rep(i, H) {
        rep(j, W) {
            if (i == 0 && j == 0) continue;
            int t = -1;
            if (j > 0) t = max(t, d[i][j - 1] + A[i][j] - P[i + j]);
            if (i > 0) t = max(t, d[i - 1][j] + A[i][j] - P[i + j]);

            d[i][j] = t;
            ans = min(ans, t);
        }
    }

    cout << -ans << endl;
}