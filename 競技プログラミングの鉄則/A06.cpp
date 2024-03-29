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
    vector<int> A(N), L(Q), R(Q), Asum(N + 1);
    Asum[0] = 0;
    rep(i, N) {
        cin >> A[i];
        Asum[i + 1] = A[i] + Asum[i];
    }
    rep(i, Q) {
        cin >> L[i] >> R[i];
    }
    rep(i, Q) {
        cout << Asum[R[i]] - Asum[L[i] - 1] << endl;
    }
}