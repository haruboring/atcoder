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
    rep(i, N) {
        sum += 2 * A[i];
        sum *= -1;
    }

    vector<ll> rain_M(N);
    rain_M[0] = -sum / 2;
    repp(i, 1, N) {
        rain_M[i] = 2 * A[i - 1] - rain_M[i - 1];
    }

    rep(i, N) {
        cout << rain_M[i] << " ";
    }
    cout << endl;
}