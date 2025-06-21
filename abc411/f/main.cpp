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
    vector<vector<mint>> A(N, vector<mint>(6));
    rep(i, N) rep(j, 6) {
        int x;
        cin >> x;
        A[i][j] = (mint)x;
    }

    vector<mint> B(6);
    rep(i, N) {
        vector<mint> nB(6);

        rep(j, 6) {
            mint x = A[i][j];
            mint y = 0;
            rep(k, 6) {
                mint a = B[k];
                y += (mint)max(x.val(), a.val());
            }
            nB[j] = y / (mint)6;
        }

        B = nB;
    }
    mint ans = 0;
    rep(i, 6) ans += B[i];
    ans /= (mint)6;

    cout << ans.val() << endl;
}
