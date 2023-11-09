#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));
    rep(i, N) {
        rep(j, M) {
            cin >> A[i][j];
        }
    }

    int ans = 0;

    rep(i, M - 1) {
        repp(j, i + 1, M) {
            int tmp = 0;
            rep(k, N) {
                tmp += max(A[k][i], A[k][j]);
            }
            ans = max(ans, tmp);
        }
    }

    cout << ans << endl;
}