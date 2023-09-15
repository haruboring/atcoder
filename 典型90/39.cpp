#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

vector<vector<int>> G;
vector<int> A;

void dfs(int v, int p = -1) {
    A[v] = 1;
    for (int u : G[v]) {
        if (u == p) continue;
        dfs(u, v);
        A[v] += A[u];
    }
}

signed main() {
    int N;
    cin >> N;
    vector<int> a(N - 1), b(N - 1);
    rep(i, N - 1) cin >> a[i] >> b[i];

    G.resize(N);
    rep(i, N - 1) {
        a[i]--;
        b[i]--;
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }

    A.resize(N);

    dfs(0);

    int ans = 0;
    repp(i, 1, N) {
        ans += A[i] * (N - A[i]);
    }

    cout << ans << endl;
}