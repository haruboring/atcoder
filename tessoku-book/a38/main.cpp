#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int D, N;
    cin >> D >> N;
    vector<int> L(N), R(N), H(N);
    rep(i, N) cin >> L[i] >> R[i] >> H[i];

    vector<int> A(D, 24);
    rep(i, N) repp(j, L[i] - 1, R[i]) A[j] = min(A[j], H[i]);
    cout << accumulate(all(A), 0LL) << endl;
}
