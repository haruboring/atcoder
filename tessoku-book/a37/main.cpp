#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M, B;
    cin >> N >> M >> B;
    vector<int> A(N), C(M);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> C[i];

    int r = accumulate(all(C), 0LL) + M * B;
    int ans = 0;
    rep(i, N) ans += A[i] * M + r;
    cout << ans << endl;
}
