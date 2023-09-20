#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    vector<ll> L(Q), R(Q), V(Q);
    rep(i, Q) cin >> L[i] >> R[i] >> V[i];

    rep(i, Q) L[i]--, R[i]--;

    vector<ll> d(N - 1);
    rep(i, N - 1) {
        d[i] = A[i] - A[i + 1];
    }
    ll BASE = 0;
    rep(i, N - 1) {
        BASE += abs(d[i]);
    }

    rep(i, Q) {
        if (L[i] != 0) {
            BASE -= abs(d[L[i] - 1]);
            d[L[i] - 1] -= V[i];
            BASE += abs(d[L[i] - 1]);
        }
        if (R[i] != N - 1) {
            BASE -= abs(d[R[i]]);
            d[R[i]] += V[i];
            BASE += abs(d[R[i]]);
        }
        cout << BASE << endl;
    }
}
