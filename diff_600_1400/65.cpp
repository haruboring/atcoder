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
    rep(i, M) cin >> A[i] >> B[i] >> C[i];

    using T = tuple<ll, ll, ll, ll>;
    vector<vector<T>> G(N, vector<T>(0));
    rep(i, M) {
        G[A[i] - 1].push_back({C[i], A[i] - 1, B[i] - 1, i});
        G[B[i] - 1].push_back({C[i], B[i] - 1, A[i] - 1, i});
    }

    priority_queue<T, vector<T>, greater<T>> pq;
    for (T e : G[0]) pq.push(e);
    vector<ll> dist(N, 1e18);
    dist[0] = 0;
    vector<int> ans(N);
    while (!pq.empty()) {
        auto [c, a, b, i] = pq.top();
        pq.pop();
        if (dist[a] + c >= dist[b]) continue;
        dist[b] = dist[a] + c;
        ans[b] = i;
        for (T e : G[b]) pq.push(e);
    }

    repp(i, 1, N) cout << ans[i] + 1 << " ";
    cout << endl;
}