#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    ll N, K, M, R;
    cin >> N >> K >> M >> R;
    vector<ll> S(N - 1);
    rep(i, N - 1) cin >> S[i];

    sort(all(S), greater<ll>());

    ll sum = 0;
    rep(i, K - 1) {
        sum += S[i];
    }
    ll need = R * K - sum;
    if (K < N && need <= S[K - 1]) {
        cout << 0 << endl;
        return 0;
    }
    if (K == N && need <= 0) {
        cout << 0 << endl;
        return 0;
    }
    if (need > M) {
        cout << -1 << endl;
        return 0;
    }
    cout << need << endl;
}