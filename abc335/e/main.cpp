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
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    vector<int> U(M), V(M);
    rep(i, M) cin >> U[i] >> V[i];

    rep(i, M) {
        U[i]--;
        V[i]--;
    }

    vector<vector<int>> G(N);
    rep(i, M) {
        G[U[i]].push_back(V[i]);
        G[V[i]].push_back(U[i]);
    }

    vector<int> ans(N, 0);

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> que;
    que.push({A[0], -1, 0});
    ans[0] = max(ans[0], 1LL);
    while (!que.empty()) {
        auto [a, s, v] = que.top();
        que.pop();
        for (int u : G[v]) {
            if (A[u] < a) continue;
            if (A[u] == a) {
                if (ans[u] >= ans[v]) continue;
                ans[u] = max(ans[u], ans[v]);
            } else {
                if (ans[u] >= ans[v] + 1) continue;
                ans[u] = max(ans[u], ans[v] + 1);
            }
            que.push({A[u], v, u});
        }
    }

    cout << ans[N - 1] << endl;
}
