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
    vector<int> A(Q), B(Q), C(Q), D(Q);
    rep(i, Q) cin >> A[i] >> B[i] >> C[i] >> D[i];

    vector<mint> H(N + 1);
    mint st = 10;
    rep(i, N) H[i + 1] = H[i] + (S[i] - 'a') * st.pow(i);
    rep(i, Q) {
        int a = A[i], b = B[i], c = C[i], d = D[i];
        if (c - a < 0) {
            swap(a, c);
            swap(b, d);
        }
        mint ss = H[b] - H[a - 1], tt = H[d] - H[c - 1];

        tt = tt / st.pow(c - a);

        if (ss == tt) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
