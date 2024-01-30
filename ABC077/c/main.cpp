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
    vector<int> A(N), B(N), C(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    rep(i, N) cin >> C[i];

    sort(all(A));
    sort(all(B));
    sort(all(C));

    vector<int> b_cnt = vector<int>(N, 0);
    rep(i, N){
        b_cnt[i] = lower_bound(all(A), B[i]) - A.begin();
    }
    int ans = 0;
    rep(i, N){
        ans += b_cnt[i] * (N - (upper_bound(all(C), B[i]) - C.begin()));
    }

    cout << ans << endl;
}
