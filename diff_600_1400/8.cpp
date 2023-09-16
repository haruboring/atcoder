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
    vector<ll> a(N), b(N);
    rep(i, N) cin >> a[i];
    rep(i, N) cin >> b[i];

    ll a_sum = 0, b_sum = 0;
    rep(i, N) {
        a_sum += a[i];
        b_sum += b[i];
    }
    ll cnt_a = 0, cnt_b = 0;
    rep(i, N) {
        if (a[i] < b[i]) {
            cnt_a += (b[i] - a[i] + 1) / 2;
            ll changed_a = ((b[i] - a[i] + 1) / 2) * 2 + a[i];
            cnt_b += changed_a - b[i];
        } else {
            cnt_b += a[i] - b[i];
        }
        // cout << cnt_a << ",, " << cnt_b << endl;
    }
    // cout << cnt_a << " " << cnt_b << endl;
    // cout << b_sum - a_sum << endl;
    // cout << cnt_b + (cnt_a - cnt_b) * 2 << endl;
    if (cnt_a >= cnt_b && cnt_b + (cnt_a - cnt_b) * 2 == b_sum - a_sum) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}