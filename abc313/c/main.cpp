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
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    ll sum = 0;
    rep(i, N) sum += A[i];
    ll ave = sum / N;
    if (sum % N == 0) {
        ll ans = 0;
        rep(i, N) ans += abs(A[i] - ave);
        debug(ave);
        cout << ans / 2 << endl;
        return 0;
    }

    ll ans = 0;
    ll up = 0, down = 0;
    rep(i, N) {
        if (A[i] == ave || A[i] == ave + 1) continue;
        if (A[i] < ave) {
            up += ave - A[i];
        } else {
            down += A[i] - (ave + 1);
        }
    }
    cout << min(up, down) + max(0LL, (max(up, down) - min(up, down))) << endl;
}