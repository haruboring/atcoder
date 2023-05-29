#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int N, M;

vector<int> A(100000 + 100), B(100000 + 100);
vector<vector<int>> G(100000 + 100, vector<int>(0));
vector<int> depths(100000 + 100, -1);
bool ans = true;
void dfs(int v, int d) {
    depths[v] = d;
    if (G[v].size() > 2) ans = false;
    for (auto next_v : G[v]) {
        if (depths[next_v] == -1) dfs(next_v, d + 1);
        if (depths[next_v] == d) ans = false;
    }
}

int main() {
    cin >> N >> M;
    rep(i, M) cin >> A[i] >> B[i];

    rep(i, M) {
        int a = A[i], b = B[i];
        G[a].push_back(b);
        G[b].push_back(a);
    }

    repp(i, 1, N + 1) {
        if (depths[i] == -1) dfs(i, 0);
    }

    if (ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}