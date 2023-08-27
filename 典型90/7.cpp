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
    rep(i, N) cin >> A.at(i);
    ll Q;
    cin >> Q;
    vector<ll> B(Q);
    rep(i, Q) cin >> B.at(i);

    sort(all(A));

    cout << endl;
    rep(i, Q) {
        ll ans = 0;
        ll id = lower_bound(all(A), B.at(i)) - A.begin();
        if (id == 0) {
            ans = abs(A.at(id) - B.at(i));
        } else if (id == N) {
            ans = abs(A.at(id - 1) - B.at(i));
        } else {
            ans = min(abs(A.at(id) - B.at(i)), abs(A.at(id - 1) - B.at(i)));
        }

        cout << ans << endl;
    }
}