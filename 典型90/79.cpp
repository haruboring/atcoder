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
    vector<vector<int>> B(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> B[i][j];

    int ans = 0;
    rep(i, H - 1) {
        rep(j, W - 1) {
            int diff = B[i][j] - A[i][j];
            A[i][j] += diff;
            A[i + 1][j] += diff;
            A[i][j + 1] += diff;
            A[i + 1][j + 1] += diff;
            ans += abs(diff);
        }
    }

    rep(i, H) {
        rep(j, W) {
            if (A[i][j] != B[i][j]) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    cout << ans << endl;
}
