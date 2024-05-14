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
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    int ans = 0;
    int sum = accumulate(all(A), 0LL);
    rep(i, N - 1) {
        sum -= A[i];
        ans += sum + A[i] * (N - i - 1);
    }

    sort(all(A));
    rep(i, N - 1) {
        int idx = lower_bound(all(A), 100'000'000 - A[i]) - A.begin();
        idx = max(i + 1, idx);
        idx = min(N, idx);
        // debug(idx);
        int cnt = N - idx;

        ans -= cnt * 100000000;
    }

    cout << ans << endl;
}
