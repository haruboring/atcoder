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
    vector<int> A(N - 1), B(N - 2);
    rep(i, N - 1) cin >> A[i];
    rep(i, N - 2) cin >> B[i];

    vector<int> dist(N, 1e18);
    dist[0] = 0;
    for (int i = 1; i < N; i++) {
        dist[i] = min(dist[i], dist[i - 1] + A[i - 1]);
        if (i > 1) dist[i] = min(dist[i], dist[i - 2] + B[i - 2]);
    }

    cout << dist[N - 1] << endl;
}
