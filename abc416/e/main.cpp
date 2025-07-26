#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

vector<vector<int>> d(500, vector<int>(500, 1e18));
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

    rep(i, M) A[i]--, B[i]--;
    rep(i, M) {
        d[A[i]][B[i]] = min(d[A[i]][B[i]], C[i]);
        d[B[i]][A[i]] = min(d[B[i]][A[i]], C[i]);
    }
    rep(i, K) D[i]--;
    rep(i, K - 1) repp(j, i + 1, K) {
        d[D[i]][D[j]] = min(d[D[i]][D[j]], T);
        d[D[j]][D[i]] = min(d[D[j]][D[i]], T);
    }

    rep(i, N) d[i][i] = 0;

    unordered_set<int> sD;
    rep(i, K) sD.insert(D[i]);

    warshall_floyd(N);
    bool nes = false;
    rep(_, Q) {
        int f;
        cin >> f;

        if (f == 1) {
            int x, y, t;
            cin >> x >> y >> t;
            x--, y--;

            if (t < d[x][y]) nes = true;
            d[x][y] = min(d[x][y], t);
            d[y][x] = min(d[y][x], t);
            if (nes) _warshall_floyd(N, x, y);
            nes = false;
        } else if (f == 2) {
            int x;
            cin >> x;
            x--;
            for (int d_ : sD) {  // 絶対ここ、キモすぎる
                if (T < d[x][d_]) nes = true;
                d[x][d_] = min(d[x][d_], T);
                d[d_][x] = min(d[d_][x], T);
                if (nes) _warshall_floyd(N, x, d_);
                nes = false;
            }
            sD.insert(x);
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
