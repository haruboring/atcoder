#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

vector<vector<int>> C(10, vector<int>(10));
void warshall_floyd(int n) {
    for (int k = 0; k < n; k++) {          // 経由する頂点
        for (int i = 0; i < n; i++) {      // 始点
            for (int j = 0; j < n; j++) {  // 終点
                C[i][j] = min(C[i][j], C[i][k] + C[k][j]);
            }
        }
    }
}

signed main() {
    int H, W;
    cin >> H >> W;
    rep(i, 10) rep(j, 10) cin >> C[i][j];
    vector<vector<int>> A(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];

    warshall_floyd(10);

    int sum = 0;
    rep(i, H) rep(j, W) if (A[i][j] != -1) sum += C[A[i][j]][1];
    cout << sum << endl;
}
