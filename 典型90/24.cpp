#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    vector<ll> B(N);
    rep(i, N) cin >> B[i];

    ll sum = 0;
    rep(i, N) {
        sum += abs(A[i] - B[i]);
    }

    if (sum <= K && (K - sum) % 2 == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}