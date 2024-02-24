#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M;
    cin >> N >> M;
    vector<int> l(M), d(M), k(M), c(M), A(M), B(M);
    rep(i, M) cin >> l[i] >> d[i] >> k[i] >> c[i] >> A[i] >> B[i];

    rep(i, M) {
        B[i]--;
        A[i]--;
    }
    map<pair<int, int>, tuple<int, int, int, int>> info;
    rep(i, M) info[{B[i], A[i]}] = {l[i], d[i], k[i], c[i]};
    vector<vector<int>> G(N);
    rep(i, M) G[B[i]].push_back(A[i]);

    vector<bool> visited(N, false);
    vector<int> m(N, -1);
    priority_queue<pair<int, int>> q;
    q.push({1e18 + 100, N - 1});
    while (!q.empty()) {
        auto [x, v] = q.top();
        q.pop();
        if (visited[v]) continue;
        visited[v] = true;
        m[v] = x;
        for (auto u : G[v]) {
            if (visited[u]) continue;
            if (!info.count({v, u})) continue;
            auto [l, d, k, c] = info[{v, u}];
            if (x - c < l) continue;
            int nx = 0;
            if (x - c >= l + (k - 1) * d)
                nx = l + (k - 1) * d;
            else
                nx = l + (x - c - l) / d * d;
            if (nx < 0) continue;
            q.push({nx, u});
        }
    }
    // 1'000'000'000'000'000'000
    rep(i, N - 1) {
        if (m[i] == -1) {
            cout << "Unreachable" << endl;
        } else {
            cout << m[i] << endl;
        }
    }
}
