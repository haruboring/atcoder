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
    vector<vector<int>> G(N, vector<int>(0));
    rep(i, M) {
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    vector<int> dist(N, 1e9);
    set<int> s;
    dist[0] = 0;
    for (int nv : G[0]) {
        dist[nv] = 1;
        s.insert(nv);
    }
    for (int v : s) {
        for (int nv : G[v]) {
            if (dist[nv] != 1e9) continue;
            dist[nv] = 2;
        }
    }

    if (dist[N - 1] < 3) {
        cout << "POSSIBLE" << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}
