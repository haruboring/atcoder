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
    vector<vector<int>> G(N + 1, vector<int>(0));
    rep(i, M) G[A[i]].push_back(B[i]);

    int ans = 0;
    repp(i, 1, N + 1) {
        queue<int> q;
        q.push(i);
        set<int> S;
        S.insert(i);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int u : G[v]) {
                if (S.count(u)) continue;
                S.insert(u);
                q.push(u);
            }
        }
        ans += S.size();
    }

    cout << ans << endl;
}