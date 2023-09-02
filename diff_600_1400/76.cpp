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
    vector<vector<ll>> A(N, vector<ll>(N));
    rep(i, N) rep(j, N) cin >> A[i][j];
    ll Q;
    cin >> Q;
    vector<ll> S(Q), T(Q);
    rep(i, Q) cin >> S[i] >> T[i];

    rep(i, Q) S[i]--, T[i]--;

    vector<vector<ll>> G(N, vector<ll>(0));
    rep(i, N) rep(j, N) if (A[i][j] == 1) G[i].push_back(j);

    rep(i, Q) {
        ll s = S[i] % N, t = T[i] % N;

        vector<ll> dist(N, -1);
        queue<ll> q;
        q.push(s);

        ll dis = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int j = 0; j < size; j++) {
                ll v = q.front();
                q.pop();
                for (auto nv : G[v]) {
                    if (dist[nv] != -1) continue;
                    dist[nv] = dis;
                    q.push(nv);
                }
            }
            dis++;
        }

        cout << dist[t] << endl;
    }
}