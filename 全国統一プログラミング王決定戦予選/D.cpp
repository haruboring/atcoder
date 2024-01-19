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
    vector<int> A(N - 1 + M), B(N - 1 + M);
    rep(i, N - 1 + M) cin >> A[i] >> B[i];

    vector<vector<int>> G(N), backG(N);
    vector<int> deg(N);
    rep(i, N - 1 + M) {
        A[i]--, B[i]--;
        G[A[i]].push_back(B[i]);
        backG[B[i]].push_back(A[i]);
        deg[B[i]]++;
    }

    queue<int> q;
    int root = -1;
    rep(i, N) {
        if (deg[i] == 0) {
            q.push(i);
            root = i;
        }
    }
    vector<int> order(N);
    int cnt = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        order[v] = cnt++;
        for (auto nv : G[v]) {
            deg[nv]--;
            if (deg[nv] == 0) q.push(nv);
        }
    }

    vector<int> parents(N);
    rep(i, N) {
        int bv = root;
        for (auto v : backG[i]) {
            if (order[v] > order[bv]) {
                bv = v;
            }
        }
        if (bv != -1) {
            parents[i] = bv;
        }
    }

    rep(i, N) {
        if (i == root) {
            cout << 0 << endl;
            continue;
        }
        cout << parents[i] + 1 << endl;
    }
}