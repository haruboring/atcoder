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
    vector<ll> A(M), B(M), C(M);
    rep(i, M) {
        cin >> A[i] >> B[i] >> C[i];
        A[i]--;
        B[i]--;
    }

    vector<vector<ll>> dis(N, vector<ll>(N, 1e18));
    rep(i, M) {
        dis[A[i]][B[i]] = C[i];
        dis[B[i]][A[i]] = C[i];
    }

    rep(i, N) dis[i][i] = 0;

    rep(i, N) {
        rep(j, N) {
            rep(k, N) {
                if (i == j || j == k || k == i) continue;
                dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
            }
        }
    }

    ll ans = 1e18;
    rep(i, N) {
        ll tmp = -1;
        rep(j, N) {
            tmp = max(tmp, dis[i][j]);
        }
        ans = min(ans, tmp);
    }

    cout << ans << endl;
}