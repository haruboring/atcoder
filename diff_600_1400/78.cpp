#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N + 1), B(M + 1);
    ll sumA = 0, sumB = 0;
    A[0] = sumA;
    rep(i, N) {
        ll tmp;
        cin >> tmp;
        sumA += tmp;
        A[i + 1] = sumA;
    }
    B[0] = sumB;
    rep(i, M) {
        ll tmp;
        cin >> tmp;
        sumB += tmp;
        B[i + 1] = sumB;
    }

    ll ans = -1;
    rep(i, N + 1) {
        ll tmp = K - A[i];
        if (tmp < 0) break;
        ll j = upper_bound(all(B), tmp) - B.begin();
        if (j == 0) continue;
        ans = max(ans, i + j - 1);
    }

    cout << ans << endl;
}