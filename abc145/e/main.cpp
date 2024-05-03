#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, T;
    cin >> N >> T;
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    vector<vector<int>> dpl(N + 1, vector<int>(T + 3000, -1));
    dpl[0][0] = 0;
    rep(i, N) {
        rep(j, T) {
            if (dpl[i][j] == -1) continue;
            dpl[i + 1][j] = max(dpl[i + 1][j], dpl[i][j]);
            dpl[i + 1][j + A[i]] = max(dpl[i + 1][j + A[i]], dpl[i][j] + B[i]);
        }
    }

    vector<vector<int>> dpr(N + 1, vector<int>(T + 3000, -1));
    dpr[N][0] = 0;
    for (int i = N - 1; i >= 0; i--) {
        rep(j, T) {
            if (dpr[i + 1][j] == -1) continue;
            dpr[i][j] = max(dpr[i][j], dpr[i + 1][j]);
            dpr[i][j + A[i]] = max(dpr[i][j + A[i]], dpr[i + 1][j] + B[i]);
        }
    }

    // flat
    rep(i, N) {
        rep(j, T) {
            dpl[i][j + 1] = max(dpl[i][j + 1], dpl[i][j]);
            dpr[i][j + 1] = max(dpr[i][j + 1], dpr[i][j]);
        }
    }

    int ans = 0;
    rep(i, N) {
        rep(j, T) {
            ans = max(ans, dpl[i][j] + dpr[i + 1][T - 1 - j] + B[i]);
        }
    }

    cout << ans << endl;
}
