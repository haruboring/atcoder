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

    vector<vector<int>> A(H + 1, vector<int>(W + 1, 0));
    rep(i, H) rep(j, W) {
        if ((i + j) % 2 == 0) {
            A[i + 1][j + 1] = A[i + 1][j] + c[i][j];
        } else {
            A[i + 1][j + 1] = A[i + 1][j] - c[i][j];
        }
    }
    rep(i, H) rep(j, W) {
        A[i + 1][j + 1] += A[i][j + 1];
    }

    int ans = 0;
    rep(i, H) {
        rep(j, W) {
            rep(k, H - i + 1) {
                rep(l, W - j + 1) {
                    int sum = A[i + k][j + l] - A[i][j + l] - A[i + k][j] + A[i][j];
                    if (sum != 0) continue;
                    ans = max(ans, k * l);
                }
            }
        }
    }

    cout << ans << endl;
}
