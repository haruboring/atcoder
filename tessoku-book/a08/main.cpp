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
    vector<vector<int>> X(H + 1, vector<int>(W + 1));
    rep(i, H) rep(j, W) cin >> X[i + 1][j + 1];
    int Q;
    cin >> Q;
    vector<int> A(Q), B(Q), C(Q), D(Q);
    rep(i, Q) cin >> A[i] >> B[i] >> C[i] >> D[i];

    rep(i, H + 1) rep(j, W) X[i][j + 1] += X[i][j];
    rep(j, W + 1) rep(i, H) X[i + 1][j] += X[i][j];

    rep(i, Q) cout << X[C[i]][D[i]] - X[C[i]][B[i] - 1] - X[A[i] - 1][D[i]] + X[A[i] - 1][B[i] - 1] << endl;
}
