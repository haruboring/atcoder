#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

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
            if (a != 0) G[i].push_back(a);
        }
    }

    vector<int> ans;
    vector<int> dis(N, -1);
    dis[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        ans.push_back(v);
        for (auto nv : G[v]) {
            if (dis[nv] < dis[v] + 1) {
                dis[nv] = dis[v] + 1;
                q.push(nv);
            }
        }
    }

    vector<pair<int, int>> p;
    rep(i, N) {
        p.push_back({dis[i], i});
    }
    sort(all(p));
    reverse(all(p));

    for (auto pp : p) {
        if (pp.first == 0) break;
        cout << pp.second + 1 << " ";
    }
    cout << endl;
}