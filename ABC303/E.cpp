#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int N;
vector<vector<int>> G(200000 + 100, vector<int>(0));
vector<int> visited(200000 + 100, -1);
set<int> stars;
void dfs(int pos, int d) {
    if (d % 3 == 0) stars.insert(pos);
    visited[pos] = d;
    for (auto next : G[pos]) {
        if (visited[next] != -1) continue;
        dfs(next, d + 1);
    }
}

int main() {
    cin >> N;
    vector<int> u(N - 1), v(N - 1);
    rep(i, N - 1) cin >> u[i] >> v[i];

    rep(i, N - 1) {
        G[u[i] - 1].push_back(v[i] - 1);
        G[v[i] - 1].push_back(u[i] - 1);
    }

    int reef;
    rep(i, N) {
        if (G[i].size() == 1) {
            reef = i;
            break;
        }
    }

    vector<int> ans(0);

    dfs(reef, -1);

    for (auto s : stars) {
        ans.push_back(G[s].size());
    }

    sort(all(ans));
    for (auto a : ans) {
        cout << a << " ";
    }
    cout << endl;
}