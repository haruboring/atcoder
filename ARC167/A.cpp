#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    int ans = 0;

    sort(all(A));
    reverse(all(A));

    vector<int> B(M);
    rep(i, N) {
        if (i < M)
            B[i] += A[i];
        else
            B[M - 1 - i % M] += A[i];
    }

    rep(i, M) {
        ans += B[i] * B[i];
    }

    cout << ans << endl;
}