#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll N, C, K;
    cin >> N >> C >> K;
    vector<ll> T(N);
    rep(i, N) cin >> T[i];

    sort(all(T));
    ll ans = 1;
    ll cnt = 0;
    ll st = T[0];
    rep(i, N) {
        if (T[i] > st + K || cnt == C) {
            ans++;
            cnt = 1;
            st = T[i];
            continue;
        }
        cnt++;
    }

    cout << ans << endl;
}