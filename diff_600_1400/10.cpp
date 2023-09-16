#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int R, C, D;
    cin >> R >> C >> D;
    vector<vector<int> > A(R, vector<int>(C));
    rep(i, R) {
        rep(j, C) {
            cin >> A[i][j];
        }
    }

    int ans = -1;
    rep(i, R) {
        rep(j, C) {
            if (i + j <= D && (i + j) % 2 == D % 2) {
                ans = max(ans, A[i][j]);
            }
        }
    }
    cout << ans << endl;
}