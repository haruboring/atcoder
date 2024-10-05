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
    vector<int> u(M), v(M), w(M);
    rep(i, M) cin >> u[i] >> v[i] >> w[i];

    rep(i, M) u[i]--, v[i]--;

    vector<vector<int>> G(N);
    rep(i, M) {
        G[u[i]].push_back(v[i]);
        G[v[i]].push_back(u[i]);
    }
    map<pair<int, int>, int> mp;
    rep(i, M) {
        mp[{u[i], v[i]}] = w[i];
        mp[{v[i], u[i]}] = -w[i];
    }

    vector<bool> visited(N, false);
    vector<int> num(N);

    rep(i, N) {
        if (visited[i]) continue;
        queue<int> q;
        q.push(i);
        num[i] = 0;
        while (!q.empty()) {
            int now = q.front();
            visited[now] = true;
            q.pop();
            for (int next : G[now]) {
                if (visited[next]) continue;
                num[next] = num[now] + mp[{now, next}];
                q.push(next);
            }
        }
    }

    rep(i, N) cout << num[i] << " ";
    cout << endl;
}
