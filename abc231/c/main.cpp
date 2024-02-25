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
    vector<int> x(Q);
    rep(i, Q) cin >> x[i];

    sort(all(A));

    rep(i, Q) {
        int ans = A.end() - lower_bound(all(A), x[i]);
        cout << ans << endl;
    }
}
