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
    vector<int> K(Q);
    rep(i, Q) cin >> K[i];

    vector<int> D(N + 1);
    D[0] = A[0] - 1;
    rep(i, N - 1) {
        D[i + 1] = A[i + 1] - A[i] - 1;
    }
    rep(i, N - 1) D[i + 1] += D[i];
    D[N] = 1e18;

    rep(i, Q) {
        auto idx = lower_bound(all(D), K[i]) - D.begin();
        cout << K[i] + idx << endl;
    }
}
