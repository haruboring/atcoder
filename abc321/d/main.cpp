#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M, P;
    cin >> N >> M >> P;
    vector<int> A(N), B(M);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];

    vector<int> B_sum(M + 1);

    sort(all(A));
    sort(all(B));
    rep(i, M) {
        B_sum[i + 1] = B_sum[i] + B[i];
    }

    int ans = 0;

    for (int i = 0; i < N; ++i) {
        int base = A[i];

        int itr = upper_bound(all(B), P - base) - B.begin();

        ans += itr * base + B_sum[itr] + (M - itr) * P;
    }

    cout << ans << endl;
}