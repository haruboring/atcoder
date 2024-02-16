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
    vector<int> A(N - 1), B(N - 1), X(N - 1);
    rep(i, N - 1) cin >> A[i] >> B[i] >> X[i];
    rep(i, N - 1) X[i]--;

    map<pair<int, int>, int> dist;
    rep(i, N - 1) dist[{i, i + 1}] = A[i];
    rep(i, N - 1) {
        if (dist.count({i, X[i]})) {
            dist[{i, X[i]}] = min(dist[{i, X[i]}], B[i]);
        } else {
            dist[{i, X[i]}] = B[i];
        }
    }

    vector<vector<int>> G(N, vector<int>(0));
    for (auto [k, v] : dist) {
        auto [i, j] = k;
        G[i].push_back(j);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    vector<int> d(N, 1e18);
    d[0] = 0;
    while (!pq.empty()) {
        auto [c, v] = pq.top();
        pq.pop();
        if (d[v] < c) continue;
        for (auto u : G[v]) {
            if (d[u] > d[v] + dist[{v, u}]) {
                d[u] = d[v] + dist[{v, u}];
                pq.push({d[u], u});
            }
        }
    }

    cout << d[N - 1] << endl;
}
