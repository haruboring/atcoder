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
    vector<ll> A(N), B(M);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];

    ll left = 0, right = 1e18;
    ll tm = -1;
    while (right - left > 1) {
        ll mid = (left + right) / 2;
        ll cnt = 0;
        ll want_sell = 0, want_buy = 0;
        rep(i, N) {
            if (mid >= A[i]) want_sell++;
        }
        rep(i, M) {
            if (mid <= B[i]) {
                want_sell--;
                want_buy++;
            }
        }
        debug(mid);
        // cout << "want_sell: " << want_sell << endl;
        tm = want_buy;
        debug(tm);
        if (want_sell < 0)
            left = mid;
        else if (want_sell >= 0)
            right = mid;
    }

    cout << right << endl;
}