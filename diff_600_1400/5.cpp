#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M;
    cin >> N >> M;
    vector<int> a(M), b(M);
    rep(i, M) cin >> a[i] >> b[i];
    vector<vector<int>> g(N + 1, vector<int>(0));
    rep(i, M) {
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    vector<int> ans(N + 1, -1);
    queue<int> q;
    q.push(1);
    ans[1] = 0;
    while (q.size()) {
        int now_island = q.front();
        q.pop();
        for (int next_island : g[now_island]) {
            if (ans[next_island] == -1) {
                ans[next_island] = ans[now_island] + 1;
                q.push(next_island);
            }
        }
    }
    if (ans[N] == 2) {
        cout << "POSSIBLE" << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}