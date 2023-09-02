#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

vector<vector<int>> G(200000 + 100, vector<int>(0));
vector<int> add(200000 + 100);
vector<int> counter(200000 + 100);

void dfs(int v, int p = -1) {
    counter[v] = add[v];
    if (p != -1) counter[v] += counter[p];
    for (int u : G[v]) {
        if (u == p) continue;
        dfs(u, v);
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N - 1), B(N - 1);
    rep(i, N - 1) cin >> A[i] >> B[i];
    vector<int> P(Q), X(Q);
    rep(i, Q) cin >> P[i] >> X[i];

    rep(i, N - 1) {
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    rep(i, Q) add[P[i]] += X[i];

    dfs(1);

    repp(i, 1, N + 1) cout << counter[i] << " ";
    cout << endl;
}