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
    vector<int> A(M), B(M);
    rep(i, M) cin >> A[i] >> B[i];

    rep(i, M) A[i]--, B[i]--;

    vector<vector<int>> G(N);
    rep(i, M) {
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    int ans = -1;
    vector<bool> visited(N, false);
    rep(i, N) {
        if (visited[i]) continue;
        queue<int> q;
        q.push(i);
        visited[i] = true;
        int cnt = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cnt++;
            for (int u : G[v]) {
                if (visited[u]) continue;
                visited[u] = true;
                q.push(u);
            }
        }
        ans = max(ans, cnt);
    }

    cout << ans << endl;
}
