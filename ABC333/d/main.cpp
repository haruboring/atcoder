#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

vector<int> par(300000 + 100);

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
    int N;
    cin >> N;
    vector<int> u(N - 1), v(N - 1);
    rep(i, N - 1) cin >> u[i] >> v[i];

    init(N);
    rep(i, N - 1) {
        if (u[i] - 1 == 0 || v[i] - 1 == 0) continue;
        unite(u[i] - 1, v[i] - 1);
    }

    int max_subtree_size = -1;
    map<int, int> subtree_size;
    rep(i, N) {
        subtree_size[root(i)]++;
        max_subtree_size = max(max_subtree_size, subtree_size[root(i)]);
    }

    cout << N - max_subtree_size << endl;
}