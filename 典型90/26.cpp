#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N - 1), B(N - 1);
    rep(i, N - 1) cin >> A[i] >> B[i];

    vector<vector<ll>> G(N);
    rep(i, N - 1) {
        G[A[i] - 1].push_back(B[i] - 1);
        G[B[i] - 1].push_back(A[i] - 1);
    }

    vector<ll> dist(N, -1);
    queue<ll> q;
    q.push(0);
    dist[0] = 0;
    while (!q.empty()) {
        ll v = q.front();
        q.pop();
        for (ll nv : G[v]) {
            if (dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            q.push(nv);
        }
    }

    vector<pair<ll, ll>> even_pairs, odd_pairs;
    rep(i, N) {
        if (dist[i] % 2 == 0) {
            even_pairs.push_back(make_pair(dist[i], i));
        } else {
            odd_pairs.push_back(make_pair(dist[i], i));
        }
    }

    vector<pair<ll, ll>> ans = even_pairs;
    if (odd_pairs.size() > even_pairs.size()) {
        ans = odd_pairs;
    }

    sort(all(ans));
    rep(i, N / 2) {
        cout << ans[i].second + 1 << " ";
    }
    cout << endl;
}