#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

// vector<vector<int>> dp(2010, vector<int>(2, -1));
// int N;
// vector<int> a(2010);
// int f(int id, int turn, int x, int y) {
//     if (id == N) return abs(x - y);

//     if (dp[id][turn] != -1) return dp[id][turn];

//     if (turn == 0) {
//         int res = -1e9;
//         repp(i, id, N) {
//             res = max(res, f(i + 1, 1, a[i], y));
//         }
//         return dp[id][turn] = res;
//     } else {
//         int res = 1e9;
//         repp(i, id, N) {
//             res = min(res, f(i + 1, 0, x, a[i]));
//         }
//         return dp[id][turn] = res;
//     }
// }

// signed main() {
//     int Z, W;
//     cin >> N >> Z >> W;
//     rep(i, N) cin >> a[i];

//     cout << f(0, 0, Z, W) << endl;
// }

signed main() {
    int N, Z, W;
    cin >> N >> Z >> W;
    vector<int> a(N);
    rep(i, N) cin >> a[i];

    if (N == 1) {
        cout << abs(a[0] - W) << endl;
        return 0;
    }

    int ans = max({abs(a[N - 1] - W), abs(a[N - 1] - a[N - 2])});
    cout << ans << endl;
}
