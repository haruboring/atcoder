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
    vector<vector<pair<int, int>>> G(N, vector<pair<int, int>>(0));
    rep(i, M) {
        int x = U[i], y = V[i];
        G[x].push_back({y, max(0LL, H[y] - H[x])});
        G[y].push_back({x, max(0LL, H[x] - H[y])});
    }

    vector<int> f(N, 1e18);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 0});
    while (!q.empty()) {
        auto [d, v] = q.top();
        q.pop();

        if (d >= f[v]) continue;
        f[v] = d;

        for (auto [nv, dd] : G[v]) {
            if (d + dd >= f[nv]) continue;
            q.push({d + dd, nv});
        }
    }

    int ans = -1e18;
    rep(i, N) {
        // cout << i << ": " << f[i] << endl;
        ans = max(ans, H[0] - H[i] - f[i]);
    }

    cout << ans << endl;
}
