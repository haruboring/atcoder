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
    int D;
    cin >> D;
    vector<int> L(D), R(D);
    rep(i, D) cin >> L[i] >> R[i];

    vector<int> l(N + 2), r(N + 2);
    rep(i, N) l[i + 1] = max(l[i], A[i]);
    rep(i, N) r[N - i] = max(r[N - i + 1], A[N - 1 - i]);

    rep(i, D) cout << max(l[L[i] - 1], r[R[i] + 1]) << endl;
}
