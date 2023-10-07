#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using mint = atcoder::modint1000000007;

signed main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> x(Q), y(Q), z(Q), w(Q);
    rep(i, Q) cin >> x[i] >> y[i] >> z[i] >> w[i];

    rep(i, Q) {
        x[i]--;
        y[i]--;
        z[i]--;
    }

    mint ans = 1;
    rep(i, 60) {
        mint cnt = 0;

        rep(bit, 1 << N) {
            bool ok = true;

            rep(j, Q) {
                if ((((bit >> x[j]) & 1) | ((bit >> y[j]) & 1) | ((bit >> z[j]) & 1)) != ((w[j] >> i) & 1)) ok = false;
            }

            if (ok) cnt++;
        }

        ans *= cnt;
    }

    cout << ans.val() << endl;
}