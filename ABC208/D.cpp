#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(M), B(M), C(M);
    rep(i, M) {
        cin >> A[i] >> B[i] >> C[i];
        A[i]--;
        B[i]--;
    }

    vector<vector<ll>> dis(N, vector<ll>(N, 1e18));
    // A -> B (cost C)
    rep(i, M) dis[A[i]][B[i]] = C[i];
    rep(i, N) dis[i][i] = 0;

    ll ans = 0;
    rep(i, N) {
        rep(j, N) {
            rep(k, N) {
                dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
                if (dis[j][k] != 1e18) ans += dis[j][k];
            }
        }
    }
    cout << ans << endl;
}
