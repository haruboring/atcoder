#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    vector<ll> tmp(3);
    rep(i, 3) cin >> tmp[i];

    sort(all(tmp));
    ll A = tmp[0], B = tmp[1], C = tmp[2];

    ll ans = 1e9;
    rep(a_cnt, 9999 + 1) {
        ll a = a_cnt * A;
        rep(b_cnt, 9999 + 1 - a_cnt) {
            ll b = b_cnt * B;
            ll c = N - a - b;
            if (c < 0) break;
            if (c % C == 0) {
                ans = min(ans, a_cnt + b_cnt + c / C);
            }
        }
    }

    cout << ans << endl;
}