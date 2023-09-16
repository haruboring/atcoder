#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N + 2), LA(N + 2), RA(N + 2);
    rep(i, N) {
        cin >> A[i + 1];
    }
    ll sum = 0;
    rep(i, N + 1) {
        sum += A[i + 1];
        LA[i + 1] = sum;
    }
    sum = 0;
    rep(i, N + 1) {
        sum += A[N - i];
        RA[N - i] = sum;
    }
    vector<ll> R(N + 1);
    R[0] = 1;
    repp(i, 1, N + 1) {
        ll ri = max(R[i - 1], (ll)i);
        while (1) {
            if (ri > N) {
                break;
            }
            if (sum - LA[i - 1] - RA[ri + 1] <= K) {
                ri++;
            } else {
                break;
            }
        }
        R[i] = ri;
    }
    ll ans = 0;
    rep(i, N) {
        ans += (R[i + 1] - (i + 1));
    }
    cout << ans << endl;
}