#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    vector<int> L(Q), R(Q);
    rep(i, Q) cin >> L[i] >> R[i];

    vector<int> B(N + 1);
    rep(i, N) {
        B[i + 1] = B[i] + A[i];
    }

    rep(i, Q) {
        cout << B[R[i]] - B[L[i] - 1] << endl;
    }
}
