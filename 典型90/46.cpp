#include "atcoder/all"
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
    vector<ll> A(N), B(N), C(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    rep(i, N) cin >> C[i];

    map<ll, ll> mpA, mpB, mpC;
    rep(i, 46) {
        mpA[i] = 0;
        mpB[i] = 0;
        mpC[i] = 0;
    }
    rep(i, N) {
        mpA[A[i] % 46]++;
        mpB[B[i] % 46]++;
        mpC[C[i] % 46]++;
    }

    ll ans = 0;
    rep(i, 46) {
        rep(j, 46) {
            rep(k, 46) {
                if ((i + j + k) % 46 == 0) {
                    ans += mpA[i] * mpB[j] * mpC[k];
                }
            }
        }
    }

    cout << ans << endl;
}
