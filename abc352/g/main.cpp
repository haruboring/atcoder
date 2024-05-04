#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using mint = atcoder::modint998244353;
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
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    vector<mint> aa(N);
    rep(i, N) aa[i] = mint(A[i]) * mint(A[i] - 1);
    mint aa_sum = accumulate(all(aa), mint(0));
    vector<mint> alls(N);
    mint tmp = N;
    alls[1] = tmp;
    repp(i, 1, N) {
        tmp *= N - i;
        alls[i + 1] = tmp;
    }

    mint ans = 0;
    for (int i = 2; i < N; i++) {
        ans += aa_sum / alls[i];
    }
}
