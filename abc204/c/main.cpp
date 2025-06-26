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

    vector<vector<int>> G(N, vector<int>(0));
    rep(i, M) G[A[i] - 1].push_back(B[i] - 1);

    int cnt = 0;
    rep(i, N) {
        vector<bool> dist(N, false);
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int v = q.front();
            q.pop();

            if (dist[v]) continue;
            dist[v] = true;
            cnt++;

            for (int nv : G[v]) {
                if (dist[nv]) continue;
                q.push(nv);
            }
        }
    }

    cout << cnt << endl;
}
