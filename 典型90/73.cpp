#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int MOD = 1e9 + 7;
vector<vector<int>> dp(200000 + 100, vector<int>(3));
vector<vector<int>> G(200000 + 100, vector<int>(0));
vector<char> c(200000 + 100);

void dfs(int pos, int pre = -1) {
    int val1 = 1, val2 = 1;
    for (auto next : G[pos]) {
        if (next == pre) continue;
        dfs(next, pos);
        if (c[pos] == 'a') {
            val1 *= dp[next][0] + dp[next][2];
            val2 *= dp[next][0] + dp[next][1] + 2LL * dp[next][2];
        }
        if (c[pos] == 'b') {
            val1 *= dp[next][1] + dp[next][2];
            val2 *= dp[next][0] + dp[next][1] + 2LL * dp[next][2];
        }
        val1 %= MOD;
        val2 %= MOD;
    }

    if (c[pos] == 'a') {
        dp[pos][0] = val1;
        dp[pos][2] = (val2 - val1 + MOD) % MOD;
    } else {
        dp[pos][1] = val1;
        dp[pos][2] = (val2 - val1 + MOD) % MOD;
    }
}

signed main() {
    int N;
    cin >> N;
    rep(i, N) cin >> c[i];
    vector<int> a(N - 1), b(N - 1);
    rep(i, N - 1) cin >> a[i] >> b[i];

    rep(i, N - 1) {
        a[i]--;
        b[i]--;
    }

    rep(i, N - 1) {
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }

    dfs(0);

    cout << dp[0][2] << endl;
}