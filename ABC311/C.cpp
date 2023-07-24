#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int N;
vector<vector<int>> G(2e5 + 10, vector<int>(0));
queue<int> ans;
set<int> visited;

void dfs(int v) {
    if (ans.size() >= 2 && visited.count(v)) {
        bool b = false;
        while (!ans.empty()) {
            if (!b && ans.front() == v) {
                cout << ans.size() << endl;
                b = true;
            }
            if (b) cout << ans.front() + 1 << " ";
            ans.pop();
        }
        cout << endl;
        exit(0);
    }
    if (visited.count(v)) {
        visited.erase(v);
        ans.pop();
        return;
    }
    visited.insert(v);
    ans.push(v);
    for (int nv : G[v]) {
        dfs(nv);
    }
}

int main() {
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    rep(i, N) {
        G[i].push_back(A[i] - 1);
    }

    rep(i, 1) {
        if (visited.count(i)) continue;
        dfs(i);
    }
}