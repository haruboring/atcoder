// #include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N;
    cin >> N;
    vector<int> u(N - 1), v(N - 1);
    rep(i, N - 1) cin >> u[i] >> v[i];

    vector<vector<int>> G(N);
    rep(i, N - 1) {
        u[i]--, v[i]--;
        G[u[i]].push_back(v[i]);
        G[v[i]].push_back(u[i]);
    }

    int yu_size = 0;

    rep(i, N) {
        map<int, int> mp;
        for (int j : G[i]) mp[G[j].size() - 1]++;
        int x = G[i].size();

        for (auto [y, cnt] : mp) {
            if (y != 0) yu_size = max(yu_size, 1 + x + y * x);
            x -= cnt;
        }
    }

    cout << N - yu_size << endl;
}