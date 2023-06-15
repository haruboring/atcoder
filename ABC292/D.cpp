#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> u(M), v(M);
    rep(i, M) {
        cin >> u[i] >> v[i];
        u[i]--;
        v[i]--;
    }

    vector<vector<int>> G(N);
    rep(i, M) {
        G[u[i]].push_back(v[i]);
        G[v[i]].push_back(u[i]);
    }

    vector<bool> is_checked(N, false);
    rep(i, N) {
        if (is_checked[i]) continue;
        is_checked[i] = true;
        queue<int> q;
        q.push(i);
        int top_cnt = 0;
        int edge_cnt = 0;
        while (!q.empty()) {
            int v = q.front();
            top_cnt++;
            q.pop();
            for (auto nv : G[v]) {
                edge_cnt++;
                if (is_checked[nv]) continue;
                is_checked[nv] = true;
                q.push(nv);
            }
        }

        if (edge_cnt != 2 * top_cnt) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}