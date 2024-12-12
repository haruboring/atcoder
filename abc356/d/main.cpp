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
    int N, M;
    cin >> N >> M;

    mint ans = 0;

    rep(i, 62) {
        if (M % 2) {
            int m = mint(2).pow(i + 1).val();
            int n = mint(2).pow(i).val();
            
            ans += min(m - 1, 0LL);
        }
        M /= 2;
    }

    cout << ans.val() << endl;
}
