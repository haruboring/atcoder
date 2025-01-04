// #include "atcoder/all"
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
    vector<int> x(N), y(N), P(N);
    rep(i, N) cin >> x[i] >> y[i] >> P[i];

    int ans = 1e18;
    rep(i, N) {
        vector<int> cs(N, 100);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, i});
        while (!pq.empty()) {
            auto [c, p] = pq.top();
            pq.pop();
            if (cs[p] != 100) continue;
            cs[p] = c;
            rep(np, N) {
                if (np == p) continue;
                int d = abs(x[p] - x[np]) + abs(y[p] - y[np]);
                pq.push({(d + P[p] - 1) / P[p], np});
            }
        }

        int cost = 0;
        rep(j, N) cost = max(cost, cs[j]);
        ans = min(ans, cost);
    }

    cout << ans << endl;
}