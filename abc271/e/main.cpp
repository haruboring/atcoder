#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> A(M), B(M), C(M);
    rep(i, M) cin >> A[i] >> B[i] >> C[i];
    vector<int> E(K);
    rep(i, K) cin >> E[i];

    rep(i, M) {
        A[i]--;
        B[i]--;
    }
    rep(i, K) E[i]--;

    vector<int> dist(N, 1e18);
    dist[0] = 0;
    for (int i : E) dist[B[i]] = min(dist[B[i]], dist[A[i]] + C[i]);

    if (dist[N - 1] == 1e18) {
        cout << -1 << endl;
    } else {
        cout << dist[N - 1] << endl;
    }
}
