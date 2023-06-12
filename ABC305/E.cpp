#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<int>> G(N, vector<int>(0));
    vector<int> a(M), b(M);
    rep(i, M) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
    vector<int> p(K), h(K);
    rep(i, K) {
        cin >> p[i] >> h[i];
        p[i]--;
    }

    vector<int> ans(N, -1);
    priority_queue<pair<int, int>> pq;
    rep(i, K) pq.push(make_pair(h[i], p[i]));
    while (!pq.empty()) {
        auto [h, v] = pq.top();
        pq.pop();
        ans[v] = h;
        for (auto nv : G[v]) {
            if (h > 0 && h - 1 > ans[nv]) {
                ans[nv] = h - 1;
                pq.push(make_pair(h - 1, nv));
            }
        }
    }

    cout << N - count(all(ans), -1) << endl;
    rep(i, N) {
        if (ans[i] != -1) cout << i + 1 << " ";
    }
    cout << endl;
}