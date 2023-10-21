#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N;
    cin >> N;
    vector<int> T(N), K(N);
    vector<vector<int>> A(N, vector<int>(0));
    rep(i, N) {
        cin >> T[i] >> K[i];
        rep(j, K[i]) {
            int a;
            cin >> a;
            A[i].push_back(a - 1);
        }
    }

    vector<vector<int>> G(N, vector<int>(0));
    rep(i, N) {
        rep(j, K[i]) {
            G[i].push_back(A[i][j]);
        }
    }

    vector<bool> visited(N, false);
    int ans = 0;
    visited[N - 1] = true;
    queue<int> q;
    q.push(N - 1);
    while (!q.empty()) {
        int v = q.front();
        ans += T[v];
        q.pop();

        for (int nv : G[v]) {
            if (!visited[nv]) {
                visited[nv] = true;
                q.push(nv);
            }
        }
    }

    cout << ans << endl;
}