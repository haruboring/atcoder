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
    int N, L;
    cin >> N >> L;
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    mint ans = 0;
    repp(i, 1, 1 << N) {
        bitset<20> bs(i);
        mint cnt = 0;
        rep(j, 26) {
            bool ok = true;
            char c = 'a' + j;
            rep(k, N) {
                if (bs[k] && S[k].find(c) == string::npos) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cnt++;
            }
        }
        if (bs.count() % 2 == 1) {
            ans += cnt.pow(L);
        } else {
            ans -= cnt.pow(L);
        }
    }
    cout << ans.val() << endl;
}
// 2^26 = 67'108'864
// 2*18 = 262'144