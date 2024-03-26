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

    sort(all(A));
    vector<int> ruiseki(N + 1);
    rep(i, N) ruiseki[i + 1] = ruiseki[i] + A[i];

    int l = 0, r = 1e6;
    while (r - l > 1) {
        int m = (l + r) / 2;
        int cnt = 0;
        rep(i, N) {
            int idx = lower_bound(all(A), m - A[i]) - A.begin();
            cnt += N - idx;
        }

        if (cnt > M) {
            l = m;
        } else {
            r = m;
        }
    }

    int sum = 0;
    int cnt = 0;
    rep(i, N) {
        int idx = lower_bound(all(A), r - A[i]) - A.begin();
        sum += ruiseki[N] - ruiseki[idx] + A[i] * (N - idx);
        cnt += N - idx;
    }

    cout << sum + l * (M - cnt) << endl;
}
