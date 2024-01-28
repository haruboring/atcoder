#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

vector<int> par(200000 + 100);

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
    int N, M;
    cin >> N >> M;
    vector<int> U(M), V(M);
    rep(i, M) cin >> U[i] >> V[i];

    rep(i, M) {
        U[i]--;
        V[i]--;
    }

    vector<set<int>> st(N);
    rep(i, M) {
        st[U[i]].insert(V[i]);
        st[V[i]].insert(U[i]);
    }

    init(N);
    rep(i, M) {
        unite(U[i], V[i]);
    }
    map<int, int> mp1, mp2;
    rep(i, N) {
        mp1[root(i)]++;
        mp2[root(i)] += st[i].size();
    }

    for (auto [v, cnt] : mp1) {
        if (mp2[v] != 2 * cnt) {
            cout << 0 << endl;
            return 0;
        }
    }

    queue<int> q;
    rep(i, N) {
        if (st[i].size() == 1) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        int u = *st[v].begin();
        st[u].erase(v);
        st[v].erase(u);

        if (st[u].size() == 1) {
            q.push(u);
        }
    }

    init(N);

    rep(i, N) {
        if (st[i].size() == 0) continue;
        for (int j : st[i]) {
            unite(i, j);
        }
    }

    set<int> rt;
    rep(i, N) {
        if (st[i].size() == 0) continue;
        rt.insert(root(i));
        debug(root(i));
    }

    int MOD = 998244353;
    int ans = 1;
    rep(i, rt.size()) {
        ans *= 2;
        ans %= MOD;
    }

    debug(ans);

    cout << ans << endl;
}
