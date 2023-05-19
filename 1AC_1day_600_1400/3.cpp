#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int N;
vector<vector<int>> G(100000 + 1);
vector<int> A(100000 - 1), B(100000 - 1);
vector<int> C(100000 + 1);

set<int> ans;
vector<bool> visited(100000 + 1, false);

multiset<int> s;

void dfs(int top) {
    visited[top] = true;

    if (s.count(C[top]) == 0) {
        ans.insert(top);
    }
    s.insert(C[top]);

    for (auto next_top : G[top]) {
        if (!visited[next_top]) {
            dfs(next_top);
        }
    }
    s.erase(s.find(C[top]));
}

int main() {
    cin >> N;

    rep(i, N) cin >> C[i + 1];
    rep(i, N - 1) cin >> A[i] >> B[i];
    rep(i, N - 1) {
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    dfs(1);

    for (int a : ans) {
        cout << a << endl;
    }
}