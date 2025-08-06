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
    vector<int> U(M), V(M);
    rep(i, M) cin >> U[i] >> V[i];

    rep(i, M) U[i]--, V[i]--;

    init(N);
    vector<int> bad;
    rep(i, M) {
        if (root(U[i]) == root(V[i])) bad.push_back(U[i]);
        unite(U[i], V[i]);
    }

    set<int> rs;
    rep(i, N) rs.insert(root(i));
    for (int b : bad) {
        if (rs.count(root(b))) rs.erase(root(b));
    }

    cout << rs.size() << endl;
}
