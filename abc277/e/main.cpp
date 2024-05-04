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
    vector<int> U(M), V(M), A(M);
    rep(i, M) cin >> U[i] >> V[i] >> A[i];
    vector<int> S(K);
    rep(i, K) cin >> S[i];

    rep(i, M) U[i]--, V[i]--;
    rep(i, K) S[i]--;
    rep(i, M) if (A[i] == 0) A[i] = -1;

    vector<vector<pair<int, int>>> G(2 * N);
    rep(i, M) {
        G[U[i]].push_back({V[i], A[i]});
        G[V[i]].push_back({U[i], A[i]});
        G[U[i] + N].push_back({V[i] + N, -A[i]});
        G[V[i] + N].push_back({U[i] + N, -A[i]});
    }
    rep(i, K) {
        G[S[i]].push_back({S[i] + N, 0});
        G[S[i] + N].push_back({S[i], 0});
    }

    vector<int> dist(2 * N, 1e18);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    dist[0] = 0;
    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        if (dist[v] < d) continue;
        for (auto [nv, w] : G[v]) {
            if (w == -1) {
                continue;
            } else if (w == 0) {
                if (dist[nv] > d) {
                    dist[nv] = d;
                    pq.push({d, nv});
                }
            } else {
                if (dist[nv] > d + 1) {
                    dist[nv] = d + 1;
                    pq.push({d + 1, nv});
                }
            }
        }
    }

    if (min(dist[N - 1], dist[2 * N - 1]) == 1e18) {
        cout << -1 << endl;
    } else {
        cout << min(dist[N - 1], dist[2 * N - 1]) << endl;
    }
}
