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
    vector<int> A(N - 1), B(N - 1), C(N - 1);
    rep(i, N - 1) cin >> A[i] >> B[i] >> C[i];
    int Q, K;
    cin >> Q >> K;
    vector<int> X(Q), Y(Q);
    rep(i, Q) cin >> X[i] >> Y[i];

    rep(i, N - 1) {
        A[i]--;
        B[i]--;
    }
    rep(i, Q) {
        X[i]--;
        Y[i]--;
    }
    vector<vector<pair<int, int>>> G(N);
    rep(i, N - 1) {
        G[A[i]].emplace_back(B[i], C[i]);
        G[B[i]].emplace_back(A[i], C[i]);
    }

    vector<int> dist(N, -1);
    dist[K - 1] = 0;
    queue<int> q;
    q.push(K - 1);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto [nv, w] : G[v]) {
            if (dist[nv] != -1) continue;
            dist[nv] = dist[v] + w;
            q.push(nv);
        }
    }

    rep(i, Q) {
        cout << dist[X[i]] + dist[Y[i]] << endl;
    }
}