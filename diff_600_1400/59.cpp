#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> S(N);
    rep(i, N) cin >> S[i];

    vector<ll> sub(N);
    sub[0] = S[0];
    sub[1] = S[1] - S[0];
    rep(i, N - 2) {
        sub[i + 2] = S[i + 2] - sub[i] - sub[i + 1];
    }
    ll a_min = 1e9, b_min = 1e9;
    ll min_a_plus_b = 1e9;
    rep(i, N) {
        if (i % 3 == 0) {
            min_a_plus_b = min(min_a_plus_b, sub[i]);
        }
        if (i % 3 == 1) {
            a_min = min(a_min, sub[i]);
        }
        if (i % 3 == 2) {
            b_min = min(b_min, sub[i]);
        }
    }
    a_min = max(-a_min, 0LL);
    b_min = max(-b_min, 0LL);
    if (min_a_plus_b - (a_min + b_min) < 0) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    ll a = a_min, b = b_min;
    cout << a << " " << b << " ";
    rep(i, N) {
        if (i % 3 == 0) {
            cout << sub[i] - a - b << " ";
        }
        if (i % 3 == 1) {
            cout << a + sub[i] << " ";
        }
        if (i % 3 == 2) {
            cout << b + sub[i] << " ";
        }
    }
    cout << endl;
}
