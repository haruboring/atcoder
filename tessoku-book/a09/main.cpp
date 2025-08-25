#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int H, W, N;
    cin >> H >> W >> N;
    vector<int> A(N), B(N), C(N), D(N);
    rep(i, N) cin >> A[i] >> B[i] >> C[i] >> D[i];

    vector<vector<int>> h(1500 + 100, vector<int>(1500 + 100, 0));
    rep(i, N) {
        h[A[i]][B[i]]++;
        h[A[i]][D[i] + 1]--;
        h[C[i] + 1][B[i]]--;
        h[C[i] + 1][D[i] + 1]++;
    }
    rep(i, 1500 + 10) rep(j, 1500 + 10) h[i + 1][j] += h[i][j];
    rep(i, 1500 + 10) rep(j, 1500 + 10) h[i][j + 1] += h[i][j];
    rep(i, H) {
        rep(j, W) {
            cout << h[i + 1][j + 1] << " ";
        }
        cout << endl;
    }
}
