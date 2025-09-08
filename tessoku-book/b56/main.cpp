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
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;

    mint st = 1000;
    vector<mint> H(N + 1), rH(N + 1);
    rep(i, N) H[i + 1] = H[i] + (S[i] - 'a') * st.pow(i), rH[i + 1] = rH[i] + (S[N - 1 - i] - 'a') * st.pow(i);

    rep(_, Q) {
        int a, b;
        cin >> a >> b;

        mint oo = H[b] - H[a - 1], rr = rH[N + 1 - a] - rH[N - b];

        if (N - b - a + 1 >= 0) {
            rr = rr / st.pow(N - b - a + 1);
        } else {
            rr = rr * st.pow(-(N - b - a + 1));
        }

        if (oo == rr) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
