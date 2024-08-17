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
    int N;
    cin >> N;

    string S = to_string(N);
    mint base = 1;
    rep(i, S.size()) base *= 10;

    mint ans = mint(1 - base.pow(N)) * mint(N) * mint(1 - base).inv();
    cout << ans.val() << endl;
}
