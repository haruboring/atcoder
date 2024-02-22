#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

vector<bool> seen(100000);  // 探索したか記録
vector<vector<int>> G(100 + 1, vector<int>(0));

void dfs(int v) {
    seen[v] = true;
    for (auto e : G[v]) {
        if (!seen[e]) {  // 訪問済みでなければ探索
            dfs(e);
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    rep(i, 100000) {
        seen[i] = false;
    }
    int cnt = 0;
    for (int i = 1; i < n+1; i++) {
        if (!seen[i]) {
            dfs(i);
            cnt++;  // dfsした回数をカウント
        }
    }
    cout << cnt << endl;
    return 0;
}