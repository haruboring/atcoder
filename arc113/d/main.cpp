#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using mint = atcoder::modint998244353;

signed main() {
    int N, M, K_;
    cin >> N >> M >> K_;

    if (N == 1 || M == 1) {
        mint K = mint(K_);
        mint ans = K.pow(N * M);
        cout << ans.val() << endl;

        return 0;
    }

    mint K = mint(K_);
    mint ans = 0;
    for (mint i = 1; i.val() <= K.val(); i++) {
        ans += ((K - i + 1).pow(M) - (K - i).pow(M)) * i.pow(N);
    }

    cout << ans.val() << endl;
}
