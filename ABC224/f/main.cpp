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
    string S, rS;
    cin >> S;
    rS = S;
    reverse(all(rS));

    mint base = 1;
    vector<mint> tmp(S.size(), 0);
    tmp[0] = rS[0] - '0';
    mint wa = tmp[0];
    rep(i, S.size() - 1) {
        base = 10 * base + mint(2).pow(i);
        tmp[i + 1] = tmp[i] + base * (rS[i + 1] - '0');
    }
    rep(i, S.size()) debug(tmp[i].val());

    vector<mint> dp(S.size() + 1, 0);
    wa = 0;
    rep(i, S.size()) {
        wa += dp[i];
        dp[i + 1] = wa + tmp[i];
    }
    cout << dp[S.size()].val() << endl;
}
