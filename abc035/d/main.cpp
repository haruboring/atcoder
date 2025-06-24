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
    vector<int> A_(N);
    rep(i, N) cin >> A_[i];
    vector<int> A(M), B(M), C(M);
    rep(i, M) cin >> A[i] >> B[i] >> C[i];

    rep(i, M) A[i]--, B[i]--;

    vector<vector<pair<int, int>>> G(N, vector<pair<int, int>>(0)), rG(N, vector<pair<int, int>>(0));
    rep(i, M) {
        G[A[i]].push_back({B[i], C[i]});
        rG[B[i]].push_back({A[i], C[i]});
    }
    vector<int> dist(N, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0LL, 0LL});
    while (!q.empty()) {
        auto [t, v] = q.top();
        q.pop();

        if (t >= dist[v]) continue;
        dist[v] = t;

        for (auto [nv, d] : G[v]) {
            if (t + d >= dist[nv]) continue;
            q.push({t + d, nv});
        }
    }
    vector<int> rdist(N, 1e9);
    q.push({0LL, 0LL});
    while (!q.empty()) {
        auto [t, v] = q.top();
        q.pop();

        if (t >= rdist[v]) continue;
        rdist[v] = t;

        for (auto [nv, d] : rG[v]) {
            if (t + d >= rdist[nv]) continue;
            q.push({t + d, nv});
        }
    }

    int ans = -1;
    rep(i, N) ans = max(ans, A_[i] * (T - dist[i] - rdist[i]));
    cout << ans << endl;
}
