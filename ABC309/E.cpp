#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> p(N - 1);
    rep(i, N - 1) cin >> p[i];
    map<int, int> mp;
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        mp[a - 1] = max(mp[a - 1], b + 1);
    }

    vector<vector<int>> G(N);
    rep(i, N - 1) {
        G[p[i] - 1].push_back(i + 1);
    }
    set<pair<int, int>> que;
    vector<int> dist(N, 0);
    rep(i, N) {
        if (mp.count(i)) {
            dist[i] = mp[i];
            que.insert({dist[i], i});
        } else {
            que.insert({0, i});
        }
    }
    while (!que.empty()) {
        auto [d, v] = *rbegin(que);
        dist[v] = d;
        que.erase({d, v});
        for (int nv : G[v]) {
            if (dist[nv] >= d - 1) continue;
            que.erase({mp[nv], nv});
            que.insert({d - 1, nv});
        }
    }

    int ans = 0;
    rep(i, N) {
        if (dist[i] > 0) ans++;
    }
    cout << ans << endl;
}