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
    string S;
    cin >> S;

    S = "Y" + S;
    int N = S.size();

    vector<vector<mint>> D(N + 1, vector<mint>(10, 0));
    string ch = "Xchokudai";

    D[0][0] = 1;
    // rep(i, 9) D[0][i + 1] = 1;

    rep(i, N) {
        rep(j, ch.size()) {
            if (S[i] == ch[j]) {
                cout << i << ", " << j << endl;
                D[i][j] += D[i - 1][j - 1];
            }
            D[i + 1][j] = max(D[i + 1][j].val(), D[i][j].val());
        }
    }

    // rep(i, N + 1) {
    //     rep(j, 9) cout << D[i][j].val() << " ";
    //     cout << endl;
    // }

    cout << D[N][8].val() << endl;
}
