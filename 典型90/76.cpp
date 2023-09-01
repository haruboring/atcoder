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

    ll all = 0;
    rep(i, N) all += A[i];
    if (all % 10 != 0) {
        cout << "No" << endl;
        return 0;
    }

    ll divided_size = all / 10;

    vector<ll> B(2 * N + 1);
    B[0] = 0;
    rep(i, 2 * N) B[i + 1] = B[i] + A[i % N];

    rep(i, 2 * N + 1) {
        ll st = B[i];
        ll ed = B[i] + divided_size;
        auto itr = lower_bound(all(B), ed);
        if (*itr == ed) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
}
