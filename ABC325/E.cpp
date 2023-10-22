#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, A, B, C;
    cin >> N >> A >> B >> C;
    vector<vector<int>> D(N, vector<int>(N));
    rep(i, N) rep(j, N) cin >> D[i][j];

    vector<int> dist(N, 1e18);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    set<int> used;

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (used.count(u)) continue;

        dist[u] = d;
        used.insert(u);

        rep(v, N) {
            if (u == v) continue;
            if (used.count(v)) continue;
            pq.push({d + D[u][v] * A, v});
        }
    }

    vector<int> dist1(N, 1e18);
    pq.push({0, N - 1});

    used.clear();

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (used.count(u)) continue;

        dist1[u] = d;
        used.insert(u);

        rep(v, N) {
            if (u == v) continue;
            if (used.count(v)) continue;
            pq.push({d + D[v][u] * B + C, v});
        }
    }

    int ans = 1e18;

    ans = min(ans, dist[N - 1]);
    rep(i, N) {
        ans = min(ans, dist[i] + dist1[i]);
    }

    cout << ans << endl;
}