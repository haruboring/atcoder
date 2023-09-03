#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M), C(M);
    rep(i, M) cin >> A[i] >> B[i] >> C[i];

    vector<vector<int>> weight(N, vector<int>(N, 1e9));
    rep(i, N) weight[i][i] = 0;
    rep(i, M) {
        weight[A[i] - 1][B[i] - 1] = C[i];
        weight[B[i] - 1][A[i] - 1] = C[i];
    }

    for (int k = 0; k < N; k++) {              // 経由する頂点
        for (int i = 0; i < 1; i++) {          // 始点
            for (int j = 0; j < N; j++) {  // 終点
                weight[i][j] = min(weight[i][j], weight[i][k] + weight[k][j]);
            }
        }
    }

    rep(i, N) {
        cout << weight[0][i] + weight[i][N - 1] << endl;
    }
}