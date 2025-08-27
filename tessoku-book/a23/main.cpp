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
    vector<vector<int>> A(M, vector<int>(N));
    rep(i, M) rep(j, N) cin >> A[i][j];

    vector<int> Aa(M);
    rep(i, M) {
        int t = 0;
        int k = 1;
        rep(j, N) {
            t += k * A[i][j];
            k *= 2;
        }
        Aa[i] = t;
    }

    vector<int> dist((1 << N), 1e18);
    dist[0] = 0;
    rep(i, (1 << N)) rep(j, M) dist[i | Aa[j]] = min(dist[i | Aa[j]], dist[i] + 1);

    if (dist[(1 << N) - 1] >= 1e18) dist[(1 << N) - 1] = -1;
    cout << dist[(1 << N) - 1] << endl;
}
