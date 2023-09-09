#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int N, M;
vector<int> A, B;
vector<vector<int>> G, R;

vector<bool> visited1, visited2;

vector<int> t(0);

void dfs1(int v) {
    visited1[v] = true;
    for (auto nv : G[v]) {
        if (visited1[nv]) continue;
        dfs1(nv);
    }
    t.push_back(v);
}

int dfs2(int v) {
    visited2[v] = true;
    int res = 1;
    for (auto nv : R[v]) {
        if (visited2[nv]) continue;
        res += dfs2(nv);
    }
    return res;
}

signed main() {
    cin >> N >> M;
    A = B = vector<int>(M);
    rep(i, M) cin >> A[i] >> B[i];
    rep(i, M) A[i]--, B[i]--;

    G = R = vector<vector<int>>(N);
    rep(i, M) G[A[i]].push_back(B[i]), R[B[i]].push_back(A[i]);

    visited1 = visited2 = vector<bool>(N, false);
    for (int i = 0; i < N; i++) {
        if (visited1[i]) continue;
        dfs1(i);
    }

    int ans = 0;
    reverse(all(t));
    for (auto v : t) {
        if (visited2[v]) continue;
        int res = dfs2(v);
        ans += res * (res - 1) / 2;
    }
    cout << ans << endl;
}