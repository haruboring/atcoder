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
    string S;
    cin >> S;

    rep(i, N - 1) {
        if (S[i] != '1' && S[i + 1] != '1') {
            cout << -1 << endl;
            return 0;
        }
    }

    mint ans = 0;
    reverse(all(S));
    mint p = 0;
    rep(i, N - 1) {
        if (S[i] == '1') continue;
        mint a = S[i] - '0' - 1;
        ans += a * (i + 1 + p);
        p += a * (i + 1 + p);
    }
    ans += N - 1;
    cout << ans.val() << endl;
}
