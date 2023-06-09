#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

vector<int> par(100000 + 100);
vector<ll> cnt_connected_islands(100000 + 100);

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
    if (rx == ry) {
        return 0;
    } else {
        return par[rx] = ry;
    }
}

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(M), B(M);
    rep(i, M) cin >> A[i] >> B[i];
    rep(i, M) {
        A[i]--;
        B[i]--;
    }
    reverse(all(A));
    reverse(all(B));

    init(N);

    rep(i, N) cnt_connected_islands[root(i)] = 1;

    vector<ll> ans(M);
    ll cnt = 0;
    rep(i, M) {
        ans[i] = cnt;

        if (root(A[i]) == root(B[i])) continue;

        cnt -= cnt_connected_islands[root(A[i])] * (cnt_connected_islands[root(A[i])] - 1) / 2;
        cnt -= cnt_connected_islands[root(B[i])] * (cnt_connected_islands[root(B[i])] - 1) / 2;

        cnt_connected_islands[root(B[i])] += cnt_connected_islands[root(A[i])];
        cnt_connected_islands[root(A[i])] = 0;

        unite(A[i], B[i]);
        cnt += cnt_connected_islands[root(B[i])] * (cnt_connected_islands[root(B[i])] - 1) / 2;
    }

    reverse(all(ans));
    rep(i, M) {
        cout << N * (N - 1) / 2 - ans[i] << endl;
    }
}