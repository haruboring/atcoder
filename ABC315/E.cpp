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

            if (a != 0) {
                G[i].push_back(a);
                rG[a].push_back(i);
                in[i].push_back(a);
            }
        }
    }

    vector<int> dim(N);
    rep(i, N) {
        dim[i] = G[i].size();
    }

    set<int> st;
    init(N);
    rep(i, N) {
        for (auto a : in[i]) {
            if (root(i) != root(a)) unite(i, a);
        }
    }
    rep(i, N) {
        if (root(i) == root(0)) st.insert(i);
    }

    vector<int> ans;
    queue<int> q;
    vector<bool> used(N, false);
    rep(i, N) {
        if (st.count(i) != 0 && dim[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        ans.push_back(v);
        for (auto a : rG[v]) {
            if (used[a]) continue;
            dim[a]--;
            if (dim[a] == 0) {
                q.push(a);
            }
        }
        used[v] = true;
    }

    for (auto a : ans) {
        if (a == 0) {
            break;
        }
        cout << a + 1 << " ";
    }
    cout << endl;
}