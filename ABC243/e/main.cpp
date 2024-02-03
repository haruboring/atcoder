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

    vector<vector<int>> dist(N, vector<int>(N, 1e18));
    rep(i, M) {
        A[i]--;
        B[i]--;
        dist[A[i]][B[i]] = C[i];
        dist[B[i]][A[i]] = C[i];
    }
    rep(i, N) {
        dist[i][i] = 0;
    }

    rep(k, N) {
        rep(i, N) {
            rep(j, N) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int ans = 0;
    rep(i, M) {
        bool ok = false;
        rep(j, N) {
            if (A[i] == j || j == B[i]) continue;
            if (dist[A[i]][j] + dist[j][B[i]] <= C[i]) {
                ok = true;
                break;
            }
        }
        if (ok) {
            ans++;
        }
    }
    cout << ans << endl;
}
