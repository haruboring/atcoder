// #include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, K;
    cin >> N >> K;
    vector<int> u(N - 1), v(N - 1);
    rep(i, N - 1) cin >> u[i] >> v[i];
    vector<int> X(N);
    rep(i, N) cin >> X[i];

    vector<vector<int>> G(N, vector<int>(0));
    rep(i, N) {
        G[u[i]].push_back(v[i]);
        G[v[i]].push_back(u[i]);
    }

    queue<int> q;
    q.push(0);
    int size = 0;
    vector<bool> is_visited()
    while (!q.empty()) {
        int v = q.back()
        q.pop();
        size++;

    }
}