#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

vector<int> par(200'000 + 100);

void init(int n) {
    rep(i, n) par[i] = i;
}

int root(int x) {
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
}

int unite(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if (ry < rx) swap(rx, ry);
    if (rx == ry) {
        return 0;
    } else {
        return par[rx] = ry;
    }
}

signed main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> A(M), B(M), C(M);
    rep(i, M) cin >> A[i] >> B[i] >> C[i];
    vector<int> X(Q), Y(Q);
    rep(i, Q) cin >> X[i] >> Y[i];

    rep(i, M) {
        A[i]--;
        B[i]--;
    }
    rep(i, Q) {
        X[i]--;
        Y[i]--;
    }

    vector<vector<pair<int, int>>> G(N);
    rep(i, M) {
        G[A[i]].push_back({B[i], C[i]});
        G[B[i]].push_back({A[i], -C[i]});
    }

    init(N);
    rep(i, M) {
        unite(A[i], B[i]);
    }

    map<int, int> v;
    map<pair<int, int>, int> dist;
    set<int> loop;

    rep(i, N) {
        int rt = root(i);
        if (v.count(rt)) continue;

        v[rt] = i;
        queue<int> que;
        que.push(i);
        dist[{i, i}] = 0;
        while (!que.empty()) {
            int cur = que.front();
            que.pop();
            for (auto [nxt, c] : G[cur]) {
                if (!dist.count({i, nxt})) {
                    dist[{i, nxt}] = dist[{i, cur}] + c;
                    que.push(nxt);
                } else if (dist[{i, nxt}] != dist[{i, cur}] + c) {
                    loop.insert(rt);
                }
            }
        }
    }

    rep(i, Q) {
        if (root(X[i]) != root(Y[i])) {
            cout << "nan" << endl;
        } else if (loop.count(root(X[i]))) {
            cout << "inf" << endl;
        } else {
            cout << dist[{v[root(X[i])], Y[i]}] - dist[{v[root(X[i])], X[i]}] << endl;
        }
    }
}
