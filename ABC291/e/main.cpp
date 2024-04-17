#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

// トポロジカルソート
signed main() {
    int N, M;
    cin >> N >> M;
    vector<int> X(M), Y(M);
    rep(i, M) cin >> X[i] >> Y[i];

    rep(i, M) X[i]--, Y[i]--;

    vector<int> deg(N), ans(N);
    vector<vector<int>> G(N);
    rep(i, M) {
        deg[Y[i]]++;
        G[X[i]].push_back(Y[i]);
    }
    queue<int> q;
    rep(i, N) if (deg[i] == 0) q.push(i);
    int o = 1;
    while (!q.empty()) {
        if (q.size() != 1) {
            cout << "No" << endl;
            return 0;
        }
        int v = q.front();
        q.pop();
        ans[v] = o++;
        for (int u : G[v]) {
            deg[u]--;
            if (deg[u] == 0) {
                q.push(u);
                ans[u] = v;
            }
        }
    }

    cout << "Yes" << endl;
    rep(i, N) cout << ans[i] << endl;
}
