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
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    int M;
    cin >> M;
    vector<int> x(M), y(M);
    rep(i, M) cin >> x[i] >> y[i];
    rep(i, M) {
        x[i]--;
        y[i]--;
    }

    int MOD = 1e9 + 7;

    vector<vector<int>> G(N, vector<int>(0));
    rep(i, M) {
        G[x[i]].push_back(y[i]);
        G[y[i]].push_back(x[i]);
    }

    vector<int> dist(N, -1);
    dist[a] = 0;
    queue<int> q;
    q.push(a);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto nv : G[v]) {
            if (dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            q.push(nv);
        }
    }

    int min_dist = dist[b];

    vector<vector<int>> dp(N, vector<int>(N, 0));
    dp[a][0] = 1;
    rep(i, min_dist) {
        rep(j, N) {
            for (auto nv : G[j]) {
                dp[nv][i + 1] += dp[j][i];
                dp[nv][i + 1] %= MOD;
            }
        }
    }
    cout << dp[b][min_dist] << endl;
}