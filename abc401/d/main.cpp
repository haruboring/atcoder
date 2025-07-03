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
    if (ry > rx) swap(rx, ry);
    if (rx == ry) {
        return 0;
    } else {
        return par[rx] = ry;
    }
}
signed main() {
    int N, M;
    cin >> N >> M;
    vector<int> u(M), v(M);
    rep(i, M) cin >> u[i] >> v[i];

    rep(i, M) u[i]--, v[i]--;
    vector<vector<int>> G(N, vector<int>(0));
    rep(i, M) {
        G[u[i]].push_back(v[i]);
        G[v[i]].push_back(u[i]);
    }

    set<int> s;
    s.insert(0);
    vector<int> cnt(N);
    init(N);
    map<int, int> m;
    rep(i, N) m[i]++;
    rep(v, N) {
        if (s.count(v)) s.erase(v);
        for (int cv : G[v]) {
            if (cv > v) {
                s.insert(cv);
            }
            if (cv < v) {
                // debug(v);
                if (root(v) < root(cv)) {
                    m[root(v)] += m[root(cv)];
                    m[root(cv)] = 0;
                } else if (root(v) > root(cv)) {
                    m[root(cv)] += m[root(v)];
                    m[root(v)] = 0;
                }
                unite(v, cv);
            }
        }
        if (m[0] != v + 1) {
            cout << -1 << endl;
        } else {
            cout << s.size() << endl;
        }
    }

    // debug(root(0));
}
