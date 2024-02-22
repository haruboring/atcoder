#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

set<int> S;
vector<vector<int>> G(200000 + 100, vector<int>(0));
int cnt = 1;

void dfs(int v) {
    if (cnt > 1000000 + 100) {
        return;
    }
    S.insert(v);
    for (auto a : G[v]) {
        if (S.count(a) == 0) {
            cnt++;
            dfs(a);
        }
    }
    S.erase(v);
    return;
}
int main() {
    int N, M;
    cin >> N >> M;
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1);
    cout << min(cnt, (int)1000000) << endl;
}