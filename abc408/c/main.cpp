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
    vector<int> L(M), R(M);
    rep(i, M) cin >> L[i] >> R[i];

    vector<int> A(N + 1);
    rep(i, M) {
        A[L[i] - 1]++;
        A[R[i]]--;
    }
    rep(i, N) A[i + 1] += A[i];
    int ans = 1e9;
    rep(i, N) ans = min(ans, A[i]);
    cout << ans << endl;
}
