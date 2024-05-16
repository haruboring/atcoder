#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

vector<int> par(200000 + 100);

void init(int n) {
    rep(i, n) par[i] = i;
}

int root(int x) {
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
}

int unite(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if (rx == ry) {
        return 0;
    } else {
        return par[rx] = ry;
    }
}

vector<int> topological_sort(vector<vector<int>> graph) {
    int n = graph.size();

    vector<int> indegree(n);
    for (int i = 0; i < n; i++) {
        for (int j : graph[i]) {
            indegree[j]++;
        }
    }

    vector<int> res;
    queue<int> que;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) que.push(i);
    }

    while (!que.empty()) {
        int ver = que.front();
        que.pop();
        res.push_back(ver);
        for (int i : graph[ver]) {
            indegree[i]--;
            if (indegree[i] == 0) que.push(i);
        }
    }

    return res;
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> G(N), rG(N);

    vector<vector<int>> in(N, vector<int>(0));
    rep(i, N) {
        int C;
        cin >> C;

        rep(j, C) {
            int a;
            cin >> a;
            a--;

            G[i].push_back(a);
        }
    }

    vector<bool> used(N, false);
    set<int> s;
    queue<int> q;
    q.push(0);
    used[0] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        s.insert(v);
        for (auto nv : G[v]) {
            if (used[nv]) continue;
            used[nv] = true;
            q.push(nv);
        }
    }

    s.erase(0);

    vector<int> ans = topological_sort(G);
    reverse(all(ans));

    for (auto a : ans) {
        if (s.count(a) == 0) continue;
        cout << a + 1 << " ";
    }

    cout << endl;
}