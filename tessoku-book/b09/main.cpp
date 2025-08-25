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
    vector<int> A(N), B(N), C(N), D(N);
    rep(i, N) cin >> A[i] >> B[i] >> C[i] >> D[i];

    vector<vector<int>> h(1500 + 100, vector<int>(1500 + 100, 0));
    rep(i, N) {
        h[A[i]][B[i]]++;
        h[A[i]][D[i]]--;
        h[C[i]][B[i]]--;
        h[C[i]][D[i]]++;
    }
    rep(i, 1500 + 10) rep(j, 1500 + 10) h[i + 1][j] += h[i][j];
    rep(i, 1500 + 10) rep(j, 1500 + 10) h[i][j + 1] += h[i][j];

    int cnt = 0;
    rep(i, 1500 + 10) rep(j, 1500 + 10) cnt += (h[i][j] > 0);
    cout << cnt << endl;
}
