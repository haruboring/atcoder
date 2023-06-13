#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int N, M;
vector<bool> visited(100 + 10, false);

void dfs(int v) {
    if (v == N - 1) {
        string tmp;
        cin >> tmp;
        exit(0);
    }
    visited[v] = true;
    int k;
    cin >> k;
    vector<int> G(k);
    rep(i, k) {
        cin >> G[i];
        G[i]--;
    }
    for (auto nv : G) {
        if (visited[nv]) continue;
        cout << nv + 1 << endl;
        dfs(nv);
        cout << v + 1 << endl;
        int tmp_k;
        cin >> tmp_k;
        int tmp;
        rep(i, tmp_k) {
            cin >> tmp;
        }
    }
}

int main() {
    cin >> N >> M;
    dfs(0);
}