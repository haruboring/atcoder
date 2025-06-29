#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    int Q;
    cin >> Q;
    vector<int> L(Q), R(Q);
    rep(i, Q) cin >> L[i] >> R[i];

    vector<int> wc(N + 1);
    rep(i, N) wc[i + 1] = wc[i] + A[i];

    rep(i, Q) {
        int w = wc[R[i]] - wc[L[i] - 1];
        int l = R[i] - L[i] + 1 - w;
        if (w == l) {
            cout << "draw" << endl;
        } else if (w > l) {
            cout << "win" << endl;
        } else {
            cout << "lose" << endl;
        }
    }
}
