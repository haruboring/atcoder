// """
// WAなの知ってっから！！！
// """

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
    vector<int> X(M), Y(M);
    rep(i, M) cin >> X[i] >> Y[i];

    vector<vector<int>> G(N);
    rep(i, M) G[X[i] - 1].push_back(Y[i] - 1);

    int ans = -1e9 - 100;
    int buy = A[0], sell = -1;
    vector<bool> visited(N, false);
    visited[0] = true;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        sell = max(sell, A[now]);
        ans = max(ans, sell - buy);
        buy = min(buy, A[now]);
        for (auto next : G[now]) {
            if (visited[next]) continue;
            visited[next] = true;
            q.push(next);
        }
    }

    cout << ans << endl;
}
