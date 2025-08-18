#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int L;
    cin >> L;
    vector<int> B(L);
    rep(i, L) cin >> B[i];

    vector<int> A(L);
    rep(i, L - 1) A[i + 1] = A[i] ^ B[i];

    if (B[L - 1] != (A[0] ^ A[L - 1])) {
        cout << -1 << endl;
        return 0;
    }
    rep(i, L) cout << A[i] << endl;
}
