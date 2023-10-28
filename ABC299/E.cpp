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
    vector<int> u(M), v(M);
    rep(i, M) {
        cin >> u[i] >> v[i];
        u[i]--;
        v[i]--;
    }
    int K;
    cin >> K;
    vector<int> p(K), d(K);
    rep(i, K) {
        cin >> p[i] >> d[i];
        p[i]--;
    }

    vector<vector<int>> G(N, vector<int>(0));
    rep(i, M) {
        G[u[i]].push_back(v[i]);
        G[v[i]].push_back(u[i]);
    }

    vector<bool> cant_set(N, false);
    rep(i, K) {
        queue<int> que;
        que.push(p[i]);
        vector<int> dist(N, -1);
        dist[p[i]] = 0;
        if (d[i] == 0) continue;

        cant_set[p[i]] = true;
        while (!que.empty()) {
            int now = que.front();
            que.pop();
            for (auto next : G[now]) {
                if (dist[next] != -1) continue;
                dist[next] = dist[now] + 1;
                if (dist[next] >= d[i]) continue;
                cant_set[next] = true;
                que.push(next);
            }
        }
    }

    int cnt = 0;
    rep(i, N) {
        if (!cant_set[i]) cnt++;
    }
    if (cnt == 0) {
        cout << "No" << endl;
        return 0;
    }

    vector<int> ans(N);

    rep(i, K) {
        queue<int> que;
        que.push(p[i]);
        vector<int> dist(N, -1);
        dist[p[i]] = 0;
        bool ok = false;
        while (!que.empty()) {
            int now = que.front();
            if (dist[now] == d[i] && !cant_set[now]) {
                ok = true;
                ans[now] = 1;
            }
            que.pop();
            for (auto next : G[now]) {
                if (dist[next] != -1) continue;
                dist[next] = dist[now] + 1;
                que.push(next);
            }
        }

        if (!ok) {
            cout << "No" << endl;
            return 0;
        }
    }

    if (K == 0) ans[0] = 1;

    cout << "Yes" << endl;
    rep(i, N) cout << ans[i];
    cout << endl;
}