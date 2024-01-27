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

    vector<pair<int, int>> Ai(N);
    rep(i, N) Ai[i] = make_pair(A[i], i);
    sort(all(Ai));

    vector<bool> visited(N, false);

    int ans = -1e18;
    rep(i, N) {
        auto [buy, v] = Ai[i];
        if (visited[v]) continue;
        queue<int> q;
        q.push(v);
        visited[v] = true;
        int sell = -1e18;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for (int w : G[u]) {
                if (!visited[w]) q.push(w);
                visited[w] = true;
                sell = max(sell, A[w]);
            }
        }
        debug(buy);
        debug(sell);
        ans = max(ans, sell- buy);
    }

    cout << ans << endl;
}
