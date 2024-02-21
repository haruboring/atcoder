#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using mint = atcoder::modint998244353;

const int MAX = 510000;
mint fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    const int MOD = mint::mod();
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i;
        inv[i] = MOD - inv[MOD % i] * (MOD / i);
        finv[i] = finv[i - 1] * inv[i];
    }
}

mint COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * finv[k] * finv[n - k];
}

signed main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> U(M), V(M);
    rep(i, M) cin >> U[i] >> V[i];

    rep(i, M) {
        U[i]--;
        V[i]--;
    }

    vector<vector<int>> G(N);
    rep(i, M) {
        G[U[i]].push_back(V[i]);
        G[V[i]].push_back(U[i]);
    }

    int even = 0, odd = 0;
    rep(i, N) {
        if (G[i].size() % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }

    COMinit();

    mint ans = 0;
    for (int even_cnt = 0; even_cnt <= even; even_cnt++) {
        int odd_cnt = K - even_cnt;
        if (odd_cnt < 0 || odd_cnt % 2 != 0) continue;

        ans += COM(even, even_cnt) * COM(odd, odd_cnt);
    }

    cout << ans.val() << endl;
}
