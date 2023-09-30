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
    int N, M, E;
    cin >> N >> M >> E;
    vector<int> U(E), V(E);
    rep(i, E) {
        cin >> U[i] >> V[i];
        U[i]--;
        V[i]--;
    }
    int Q;
    cin >> Q;
    vector<int> X(Q);
    set<int> st;
    rep(i, Q) {
        cin >> X[i];
        X[i]--;
        st.insert(X[i]);
    }

    init(N + M);

    map<int, int> cnt;
    rep(i, E) {
        if (st.count(i)) continue;
        unite(U[i], V[i]);
    }
    rep(i, N + M) {
        cnt[root(i)]++;
    }

    vector<int> ans(Q);
    ans[0] = 0;
    repp(i, N, N + M) ans[0] += cnt[i] - 1;
    debug(ans[0]);
    reverse(all(X));

    rep(i, Q - 1) {
        ans[i + 1] = ans[i];
        int e = X[i];
        int ru = root(U[e]);
        int rv = root(V[e]);

        unite(U[e], V[e]);
        if (ru == rv) continue;

        int tmp = -1;
        if (ru > rv) {
            cnt[ru] += cnt[rv];
            tmp = cnt[rv];
            cnt[rv] = 0;
        } else {
            cnt[rv] += cnt[ru];
            tmp = cnt[ru];
            cnt[ru] = 0;
        }

        if (ru >= N && rv >= N) continue;
        if (ru < N && rv < N) continue;
        ans[i + 1] += tmp;
    }

    reverse(all(ans));
    rep(i, Q) cout << ans[i] << endl;
}