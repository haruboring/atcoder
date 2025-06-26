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
    vector<int> T(N);
    rep(i, N) cin >> T[i];

    vector<vector<bool>> A(N + 1, vector<bool>(100000 + 100, false));
    A[0][0] = true;
    rep(i, N) {
        rep(j, 100000 + 100) {
            if (!A[i][j]) continue;
            A[i + 1][j] = true;
            A[i + 1][j + T[i]] = true;
        }
    }

    int sum = 0;
    rep(i, N) sum += T[i];

    int ans = 1e9;
    rep(i, 100000 + 100) {
        if (!A[N][i]) continue;
        ans = min(ans, max(i, sum - i));
    }

    cout << ans << endl;
}
