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
    vector<int> X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];
    int Q;
    cin >> Q;
    vector<int> A(Q), B(Q), C(Q), D(Q);
    rep(i, Q) cin >> A[i] >> B[i] >> C[i] >> D[i];

    vector<vector<int>> V(1500 + 10, vector<int>(1500 + 10));
    rep(i, N) V[X[i]][Y[i]]++;
    rep(i, 1505) rep(j, 1505) V[i][j + 1] += V[i][j];
    rep(i, 1505) rep(j, 1505) V[i + 1][j] += V[i][j];

    rep(i, Q) cout << V[C[i]][D[i]] - V[A[i] - 1][D[i]] - V[C[i]][B[i] - 1] + V[A[i] - 1][B[i] - 1] << endl;
}
