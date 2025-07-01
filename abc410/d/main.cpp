#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int N, M;
vector<vector<pair<int, int>>> G(1000 + 10, vector<pair<int, int>>());
int ans = 1e18;
vector<vector<double>> dp(1000 + 10, vector<double>(1024, false));

void dfs(int v, int pv, int num) {
    dp[v][num] = true;
    if (v == N) ans = min(ans, num);

    for (auto [nv, w] : G[v]) {
        if (dp[nv][num ^ w]) continue;
        dfs(nv, v, num ^ w);
    }

    // num ^= m[{pv, v}];
}

signed main() {
    cin >> N >> M;
    vector<int> A(M), B(M), W(M);
    rep(i, M) cin >> A[i] >> B[i] >> W[i];

    rep(i, M) G[A[i]].push_back({B[i], W[i]});

    dfs(1, 0, 0);
    debug(ans);

    if (ans == 1e18) ans = -1;
    cout << ans << endl;
}
