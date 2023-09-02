#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N;
    cin >> N;
    vector<vector<int>> D(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            cin >> D[i][j];
            D[j][i] = D[i][j];
        }
    }

    vector<int> dp(1 << N, 0);

    for (int mask = 1; mask < (1 << N); ++mask) {
        for (int u = 0; u < N; ++u) {
            if (!(mask & (1 << u))) continue;
            for (int v = u + 1; v < N; ++v) {
                if (!(mask & (1 << v))) continue;

                int prev_mask = mask ^ (1 << u) ^ (1 << v);
                dp[mask] = max(dp[mask], dp[prev_mask] + D[u][v]);
            }
        }
    }

    cout << dp[(1 << N) - 1] << endl;
    return 0;
}
