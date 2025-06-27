#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    vector<int> C(N, K / N), A_ = A;
    if (K % N == 0) {
        rep(i, N) cout << C[i] << endl;
        return 0;
    }
    sort(all(A_));
    int s = A_[K % N - 1];
    rep(i, N) if (A[i] <= s) C[i]++;

    rep(i, N) cout << C[i] << endl;
}
