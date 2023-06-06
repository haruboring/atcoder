#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> p(N);
    rep(i, N) cin >> p[i];
    rep(i, N) p[i]--;
    vector<int> x(M), y(M);
    rep(i, M) cin >> x[i] >> y[i];
    rep(i, M) {
        x[i]--;
        y[i]--;
    }

    set<int> changeable_idx;
    vector<vector<int>> G(N, vector<int>(0));
    rep(i, M) {
        G[x[i]].push_back(y[i]);
        G[y[i]].push_back(x[i]);
        changeable_idx.insert(x[i]);
        changeable_idx.insert(y[i]);
    }
    vector<int> visited(N, 0);

    int ans = 0;
    // 移動できず、一致
    rep(i, N) {
        if (changeable_idx.count(i) == 0 && p[i] == i) {
            ans++;
        } else if (visited[i] == 0) {
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            set<int> visitable_value;
            vector<int> visitable_idx;
            while (!q.empty()) {
                int now = q.front();
                visitable_value.insert(p[now]);
                visitable_idx.push_back(now);
                q.pop();
                for (auto next : G[now]) {
                    if (visited[next] == 0) {
                        visited[next] = 1;
                        q.push(next);
                    }
                }
            }

            for (auto idx : visitable_idx) {
                if (visitable_value.count(idx) != 0) {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
}