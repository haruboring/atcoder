#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

vector<vector<int>> G(200000);
vector<int> C(200000);
vector<int> sum_c(200000), sum_cd(200000);

void dfs0(int u, int p) {
    sum_c[u] = C[u];
    sum_cd[u] = 0;
    for (int v : G[u]) {
        if (v == p) continue;
        dfs0(v, u);
        sum_c[u] += sum_c[v];
        sum_cd[u] += sum_cd[v] + sum_c[v];
    }
}

int ans = 9e18;

void dfs1(int v, int p, int p_sum_c, int p_sum_cd) {
    ans = min(ans, p_sum_cd + sum_cd[v]);
    for (int nv : G[v]) {
        if (nv == p) continue;
        int np_sum_c = p_sum_c + sum_c[v] - sum_c[nv];
        dfs1(nv, v, np_sum_c, p_sum_cd + sum_cd[v] - sum_c[nv] - sum_cd[nv] + np_sum_c);
    }
}

signed main() {
    int N;
    cin >> N;
    vector<int> A(N - 1), B(N - 1);
    rep(i, N - 1) cin >> A[i] >> B[i];
    rep(i, N) cin >> C[i];

    rep(i, N - 1) A[i]--, B[i]--;

    rep(i, N - 1) {
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    dfs0(0, -1);
    dfs1(0, -1, 0, 0);

    cout << ans << endl;
}
