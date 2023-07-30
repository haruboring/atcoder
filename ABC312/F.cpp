#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> T(N), X(N);
    rep(i, N) cin >> T[i] >> X[i];

    vector<ll> free_kan(0), locked_kan(0), kankiri(0);
    rep(i, N) {
        if (T[i] == 0) {
            free_kan.push_back(X[i]);
        }
        if (T[i] == 1) locked_kan.push_back(X[i]);
        if (T[i] == 2) kankiri.push_back(X[i] + 1);
    }
    sort(all(free_kan));
    sort(all(locked_kan));
    sort(all(kankiri));
    reverse(all(free_kan));
    reverse(all(locked_kan));
    reverse(all(kankiri));

    vector<ll> free_kan_sum(0), locked_kan_sum(0), kankiri_sum(0);
    free_kan_sum.push_back(0);
    locked_kan_sum.push_back(0);
    kankiri_sum.push_back(0);
    rep(i, free_kan.size()) free_kan_sum.push_back(free_kan_sum[i] + free_kan[i]);
    rep(i, locked_kan.size()) locked_kan_sum.push_back(locked_kan_sum[i] + locked_kan[i]);
    rep(i, kankiri.size()) kankiri_sum.push_back(kankiri_sum[i] + kankiri[i]);
    kankiri_sum.push_back(1e18);

    ll sum = 0;
    rep(i, free_kan_sum.size()) {
        if (i > M) break;
        ll free_kan_ = free_kan_sum[i];
        ll used_kankiri_cnt = lower_bound(all(kankiri_sum), M - i) - kankiri_sum.begin();
        if (kankiri_sum[used_kankiri_cnt] >= 1e18) used_kankiri_cnt = 0;
        ll used_locked_kan_cnt = min(M - i - used_kankiri_cnt, kankiri_sum[used_kankiri_cnt]);
        ll sum_ = free_kan_ + locked_kan_sum[min((ll)locked_kan_sum.size(), used_locked_kan_cnt)];
        sum = max(sum, sum_);
    }

    cout << sum << endl;
}