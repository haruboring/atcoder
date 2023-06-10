#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    ll Q;
    cin >> Q;
    vector<ll> l(Q), r(Q);
    rep(i, Q) cin >> l[i] >> r[i];

    vector<ll> sleep_sum(N);
    repp(i, 1, N) {
        if (i % 2 == 0) {
            sleep_sum[i] = sleep_sum[i - 1] + A[i] - A[i - 1];
        } else {
            sleep_sum[i] = sleep_sum[i - 1];
        }
    }

    rep(i, Q) {
        ll r_sum = 0, l_sum = 0;
        ll r_idx = lower_bound(all(A), r[i]) - A.begin();

        r_sum = sleep_sum[r_idx];
        if (r_idx % 2 == 0) {
            r_sum += r[i] - A[r_idx];
        }
        ll l_idx = lower_bound(all(A), l[i]) - A.begin();
        l_sum = sleep_sum[l_idx];
        if (l_idx % 2 == 0) {
            l_sum += l[i] - A[l_idx];
        }
        cout << r_sum - l_sum << endl;
    }
}