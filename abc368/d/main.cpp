#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N - 1), B(N - 1);
    rep(i, N - 1) cin >> A[i] >> B[i];
    vector<int> V(K);
    rep(i, K) cin >> V[i];

    rep(i, N - 1) A[i]--, B[i]--;
    rep(i, K) V[i]--;

    set<int> s;
    rep(i, K) s.insert(V[i]);

    vector<set<int>> G(N);
    rep(i, N - 1) {
        G[A[i]].insert(B[i]);
        G[B[i]].insert(A[i]);
    }

    queue<int> q;
    rep(i, N) {
        if (G[i].size() == 1 && !s.count(i)) {
            q.push(i);
        }
    }

    int del_cnt = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        s.erase(v);
        del_cnt++;

        int u = *G[v].begin();
        G[u].erase(v);
        if (G[u].size() == 1 && !s.count(u)) {
            q.push(u);
        }
    }

    debug(del_cnt);

    cout << N - del_cnt << endl;
}
