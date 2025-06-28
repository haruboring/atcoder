#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N - 1), B(N - 1);
    rep(i, N - 1) cin >> A[i] >> B[i];
    vector<int> C(Q), D(Q);
    rep(i, Q) cin >> C[i] >> D[i];

    vector<vector<int>> G(N, vector<int>(0));
    rep(i, N - 1) {
        G[A[i] - 1].push_back(B[i] - 1);
        G[B[i] - 1].push_back(A[i] - 1);
    }

    vector<int> dist(N, 1e18);
    queue<pair<int, int>> q;
    q.push({0, 1});
    while (!q.empty()) {
        auto [v, d] = q.front();
        q.pop();
        if (dist[v] < 1e18) continue;
        dist[v] = d;
        for (int nv : G[v]) {
            if (dist[nv] < 1e18) continue;
            q.push({nv, d + 1});
        }
    }

    rep(i, Q) {
        if (dist[C[i] - 1] % 2 == dist[D[i] - 1] % 2) {
            cout << "Town" << endl;
        } else {
            cout << "Road" << endl;
        }
    }
}
