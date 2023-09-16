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
    vector<string> b(N);
    rep(i, N) cin >> b[i];

    vector<vector<int>> B(N, vector<int>(M));
    rep(i, N) {
        rep(j, M) {
            B[i][j] = b[i][j] - '0';
        }
    }

    vector<vector<int>> ans(N, vector<int>(M));
    // 外枠から攻めろ
    repp(i, 0, N - 2) {
        repp(j, 1, M - 1) {
            int cnt = B[i][j];
            if (cnt > 0) {
                ans[i + 1][j] += cnt;
                B[i][j] -= cnt;
                B[i + 1][j + 1] -= cnt;
                B[i + 1][j - 1] -= cnt;
                B[i + 2][j] -= cnt;
            }
        }
    }

    rep(i, N) {
        rep(j, M) {
            cout << ans[i][j];
        }
        cout << endl;
    }
}