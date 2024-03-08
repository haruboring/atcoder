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
    vector<int> H(N);
    rep(i, N) cin >> H[i];

    vector<int> U(M), V(M);
    rep(i, M) cin >> U[i] >> V[i];

    rep(i, M) U[i]--, V[i]--;

    vector<vector<int>> G(N);
    rep(i, M) {
        G[U[i]].push_back(V[i]);
        G[V[i]].push_back(U[i]);
    }

    vector<int> dist(N, 1e18);
    dist[0] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [c, v] = pq.top();
        c = -c;
        pq.pop();

        if (dist[v] < c) continue;
        for (int nv : G[v]) {
            int nc = c;
            if (H[nv] > H[v]) nc += H[nv] - H[v];
            if (nc < dist[nv]) {
                dist[nv] = nc;
                pq.push({-nc, nv});
            }
        }
    }

    int ans = 0;
    rep(i, N) {
        if (H[i] <= H[0])
            ans = max(ans, H[0] - H[i] - dist[i]);
    }

    cout << ans << endl;
}
