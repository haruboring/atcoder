#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

using mint = atcoder::modint998244353;
using S = pair<mint, int>;

vector<mint> P1(1e6 + 100), P2(1e6 + 100), P3(1e6 + 100);
S op1(S a, S b) {
    return {a.first * P1[b.second] + b.first, a.second + b.second};
}
S op2(S a, S b) {
    return {a.first + b.first * P2[a.second], a.second + b.second};
}
S op3(S a, S b) {
    return {a.first * P3[b.second] + b.first, a.second + b.second};
}
S e() {
    return S(0, 0);
}

signed main() {
    int N, Q;
    cin >> N >> Q;
    string s;
    cin >> s;

    P1[0] = 1;
    rep(i, N) P1[i + 1] = P1[i] * 2194673;
    P2[0] = 1;
    rep(i, N) P2[i + 1] = P2[i] * 1234123;
    P3[0] = 1;
    rep(i, N) P3[i + 1] = P3[i] * 2141434;

    vector<S> A(N);
    rep(i, N) A[i] = S(s[i] - 'a', 1);
    atcoder::segtree<S, op1, e> seg1(A);
    atcoder::segtree<S, op2, e> seg2(A);
    atcoder::segtree<S, op3, e> seg3(A);
    reverse(all(A));
    atcoder::segtree<S, op1, e> rseg1(A);
    atcoder::segtree<S, op2, e> rseg2(A);
    atcoder::segtree<S, op3, e> rseg3(A);

    rep(_, Q) {
        int f;
        cin >> f;
        if (f == 1) {
            int x;
            char c;
            cin >> x >> c;
            seg1.set(x - 1, S(c - 'a', 1));
            seg2.set(x - 1, S(c - 'a', 1));
            seg3.set(x - 1, S(c - 'a', 1));
            rseg1.set(N - x, S(c - 'a', 1));
            rseg2.set(N - x, S(c - 'a', 1));
            rseg3.set(N - x, S(c - 'a', 1));
        } else {
            int l, r;
            cin >> l >> r;
            int cnt = 0;
            if (seg1.prod(l - 1, r).first == rseg1.prod(N - r, N - l + 1).first) cnt++;
            if (seg2.prod(l - 1, r).first == rseg2.prod(N - r, N - l + 1).first) cnt++;
            if (seg3.prod(l - 1, r).first == rseg3.prod(N - r, N - l + 1).first) cnt++;

            if (cnt >= 2) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
}
