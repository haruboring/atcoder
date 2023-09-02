#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    vector<pair<ll, ll>> CB(M);
    rep(i, M) cin >> CB[i].second >> CB[i].first;

    sort(all(CB), greater<pair<ll, ll>>());
    vector<ll> extra(0);
    rep(i, M) {
        rep(j, CB[i].second) {
            if (extra.size() == N) break;
            extra.push_back(CB[i].first);
        }
    }
    repp(i, extra.size(), N) extra.push_back(0);

    ll ans = 0;
    sort(all(A));
    rep(i, N) ans += max(A[i], extra[i]);
    cout << ans << endl;
}