#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

vector<int> par(200'000 + 100);
vector<int> cnt(200'000 + 100, 1);

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
        cnt[ry] += cnt[rx];
        cnt[rx] = 0;
        return par[rx] = ry;
    }
}

signed main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    rep(i, M) cin >> A[i] >> B[i];

    init(N);
    rep(i, M) unite(A[i] - 1, B[i] - 1);

    int c = -1;
    rep(i, N) c = max(c, cnt[root(i)]);
    cout << c << endl;
}
