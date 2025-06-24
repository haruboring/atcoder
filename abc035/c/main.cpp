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
    vector<int> L(Q), R(Q);
    rep(i, Q) cin >> L[i] >> R[i];

    vector<int> A(N + 1);
    rep(i, Q) {
        A[L[i] - 1] += 1;
        A[R[i]] -= 1;
    }

    rep(i, N) {
        if (i > 0) A[i] += A[i - 1];
        cout << (A[i] + 100000000) % 2;
    }
    cout << endl;
}
