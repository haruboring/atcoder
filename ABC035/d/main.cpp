#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M, T;
    cin >> N >> M >> T;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    vector<int> a(M), b(M), c(M);
    rep(i, M) cin >> a[i] >> b[i] >> c[i];

    vector<vector<pair<int, int>>> G(N), backG(N);
    rep(i, M) {
        G[a[i] - 1].push_back({b[i] - 1, c[i]});
    }
    rep(i, M) {
        backG[b[i] - 1].push_back({a[i] - 1, c[i]});
    }

    vector<int> forward_dist(N, 1e18);
    queue<int> q;
    q.push(0);
    forward_dist[0] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto [nv, w] : G[v]) {
            if (forward_dist[nv] > forward_dist[v] + w) {
                forward_dist[nv] = forward_dist[v] + w;
                q.push(nv);
            }
        }
    }

    vector<int> backward_dist(N, 1e18);
    q.push(0);
    backward_dist[0] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto [nv, w] : backG[v]) {
            if (backward_dist[nv] > backward_dist[v] + w) {
                backward_dist[nv] = backward_dist[v] + w;
                q.push(nv);
            }
        }
    }

    int ans = 0;
    rep(i, N) {
        if (forward_dist[i] == 1e18) continue;
        int t = T - forward_dist[i] - backward_dist[i];
        if (t <= 0) continue;
        debug(i);
        debug(t);
        debug(A[i]);
        debug("");
        ans = max(ans, t * A[i]);
    }

    cout << ans << endl;
}
