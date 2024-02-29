#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using mint = atcoder::modint1000000007;

vector<vector<int>> G;
vector<vector<mint>> dp;
void dfs(int v, int p) {
    dp[v][0] = 1;
    dp[v][1] = 1;

    for (int u : G[v]) {
        if (u == p) continue;
        dfs(u, v);
        dp[v][0] *= dp[u][0] + dp[u][1];
        dp[v][1] *= dp[u][0];
    }
}

signed main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    rep(i, N) A[i]--, B[i]--;

    G.resize(N);
    rep(i, N - 1) {
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }
    dp.resize(N, vector<mint>(2, 0));

    dfs(0, -1);
    cout << (dp[0][0] + dp[0][1]).val() << endl;
}
