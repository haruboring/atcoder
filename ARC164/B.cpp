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
    vector<int> a(M), b(M);
    rep(i, M) cin >> a[i] >> b[i];
    vector<int> c(N);
    rep(i, N) cin >> c[i];

    vector<vector<int>> G(N, vector<int>(0));
    rep(i, M) {
        G[a[i] - 1].push_back(b[i] - 1);
        G[b[i] - 1].push_back(a[i] - 1);
    }

    vector<bool> visited(N, false);

    rep(i, N) {
        if (visited[i]) continue;
        set<int> s;
        queue<int> que;
        que.push(i);
        while (!que.empty()) {
            int v = que.front();
            visited[v] = true;
            s.insert(v);
            que.pop();
            for (int nv : G[v]) {
                if (c[v] == c[nv]) {
                    if (visited[nv] && s.count(nv)) {
                        cout << "Yes" << endl;
                        return 0;
                    }
                    continue;
                }
                if (!visited[nv]) que.push(nv);
            }
        }
    }

    cout << "No" << endl;
}
