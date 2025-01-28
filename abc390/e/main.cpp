#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, X;
    cin >> N >> X;
    vector<int> V(N), A(N), C(N);
    rep(i, N) cin >> V[i] >> A[i] >> C[i];

    vector<vector<int>> dp1(N + 1, vector<int>(X + 1, -1));
    dp1[0][0] = 0;
    rep(i, N) {
        rep(j, X + 1) {
            if (dp1[i][j] == -1) continue;
            if (V[i] != 1) {
                dp1[i + 1][j] = dp1[i][j];
                continue;
            }
            dp1[i + 1][j] = max(dp1[i + 1][j], dp1[i][j]);
            if (j + C[i] <= X) dp1[i + 1][j + C[i]] = max(dp1[i + 1][j + C[i]], dp1[i][j] + A[i]);
        }
    }

    vector<vector<int>> dp2(N + 1, vector<int>(X + 1, -1));
    dp2[0][0] = 0;
    rep(i, N) {
        rep(j, X + 1) {
            if (dp2[i][j] == -1) continue;
            if (V[i] != 2) {
                dp2[i + 1][j] = dp2[i][j];
                continue;
            }
            dp2[i + 1][j] = max(dp2[i + 1][j], dp2[i][j]);
            if (j + C[i] <= X) dp2[i + 1][j + C[i]] = max(dp2[i + 1][j + C[i]], dp2[i][j] + A[i]);
        }
    }

    vector<vector<int>> dp3(N + 1, vector<int>(X + 1, -1));
    dp3[0][0] = 0;
    rep(i, N) {
        rep(j, X + 1) {
            if (dp3[i][j] == -1) continue;
            if (V[i] != 3) {
                dp3[i + 1][j] = dp3[i][j];
                continue;
            }
            dp3[i + 1][j] = max(dp3[i + 1][j], dp3[i][j]);
            if (j + C[i] <= X) dp3[i + 1][j + C[i]] = max(dp3[i + 1][j + C[i]], dp3[i][j] + A[i]);
            // debug(dp3[i + 1][j]);
        }
    }

    for (int i = 1; i <= X; i++) {
        dp1[N][i] = max(dp1[N][i], dp1[N][i - 1]);
        dp2[N][i] = max(dp2[N][i], dp2[N][i - 1]);
        dp3[N][i] = max(dp3[N][i], dp3[N][i - 1]);
    }

    int ans = -1;
    debug(ans);
    for (int x1 = 0; x1 <= X; x1++) {
        if (dp1[N][x1] == -1) continue;
        for (int x2 = 0; x2 <= X - x1; x2++) {
            if (dp2[N][x2] == -1) continue;
            int x3 = X - x1 - x2;
            if (dp3[N][x3] == -1) continue;
            if (x1 + x2 + x3 > X) continue;
            ans = max(ans, min({dp1[N][x1], dp2[N][x2], dp3[N][x3]}));
        }
    }

    cout << ans << endl;
}
