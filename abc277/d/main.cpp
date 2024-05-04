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
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    sort(all(A));
    init(N);
    rep(i, N - 1) {
        if (A[i] == A[i + 1]) unite(i, i + 1);
        if (A[i] == A[i + 1] - 1) unite(i, i + 1);
    }
    if (A[0] == (A[N - 1] + 1) % M) unite(0, N - 1);

    map<int, int> m;
    rep(i, N) m[root(i)] += A[i];

    int ans = 0;
    for (auto [k, v] : m) {
        ans = min(ans, -v);
    }
    ans += accumulate(all(A), 0LL);

    cout << ans << endl;
}
