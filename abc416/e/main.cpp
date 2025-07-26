#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

vector<vector<int>> d(501, vector<int>(501, 1e18));
void warshall_floyd(int n) {
    for (int k = 0; k < n; k++) {          // 経由する頂点
        for (int i = 0; i < n; i++) {      // 始点
            for (int j = 0; j < n; j++) {  // 終点
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}
void _warshall_floyd(int n, int s, int t) {  // https://ei1333.github.io/algorithm/warshall-floyd.html
    // 経由する頂点
    for (int k : {s, t}) {
        for (int i = 0; i < n; i++) {      // 始点
            for (int j = 0; j < n; j++) {  // 終点
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

signed main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M), C(M);
    rep(i, M) cin >> A[i] >> B[i] >> C[i];
    int K, T;
    cin >> K >> T;
    vector<int> D(K);
    rep(i, K) cin >> D[i];
    int Q;
    cin >> Q;

    rep(i, N + 1) d[i][i] = 0;

    rep(i, M) A[i]--, B[i]--;
    rep(i, M) {
        d[A[i]][B[i]] = min(d[A[i]][B[i]], C[i]);
        d[B[i]][A[i]] = min(d[B[i]][A[i]], C[i]);
    }
    rep(i, K) D[i]--;
    rep(i, K) d[D[i]][N] = T, d[N][D[i]] = 0;

    warshall_floyd(N + 1);
    rep(_, Q) {
        int f;
        cin >> f;

        debug(f);

        if (f == 1) {
            int x, y, t;
            cin >> x >> y >> t;
            x--, y--;
            d[x][y] = min(d[x][y], t);
            d[y][x] = min(d[y][x], t);
            _warshall_floyd(N + 1, x, y);
        } else if (f == 2) {
            int x;
            cin >> x;
            x--;
            d[x][N] = T, d[N][x] = 0;
            _warshall_floyd(N + 1, x, N);
        } else {
            int sum = 0;
            rep(i, N) {
                rep(j, N) {
                    if (d[i][j] == 1e18) continue;
                    sum += d[i][j];
                }
            }
            cout << sum << endl;
        }
    }
}
