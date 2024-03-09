#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

void dfs(vector<vector<int>> &G, vector<bool> &is_visit, int pos) {
    is_visit[pos] = true;
    for (int g : G[pos]) {
        if (is_visit[g] == false) {
            dfs(G, is_visit, g);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N + 1);
    vector<bool> is_visit(N + 1, false);
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(G, is_visit, 1);
    int cnt1 = 0, cnt2 = 0;
    repp(i, 1, N + 1) {
        if (is_visit[i] == false) {
            cout << "No" << endl;
            return 0;
        }
        if (G[i].size() == 1) {
            cnt1++;
        }
        if (G[i].size() == 2) {
            cnt2++;
        }
    }
    if (cnt1 == 2 && cnt2 == N - 2) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
}