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
    vector<int> A(M), B(M), C(M);
    rep(i, M) cin >> A[i] >> B[i] >> C[i];

    rep(i, M) A[i]--, B[i]--;

    map<pair<int, int>, int> m;
    vector<vector<int>> D(N, vector<int>(N, 1e18));
    rep(i, M) D[A[i]][B[i]] = C[i];
    rep(i, N) D[i][i] = 0;

    int ans = 0;
    rep(k, N) {
        rep(i, N) {
            rep(j, N) {
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
                if (D[i][j] < 1e9) ans += D[i][j];
            }
        }
    }

    cout << ans << endl;
}
