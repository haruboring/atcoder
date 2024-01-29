#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

map<int, map<int, int>> mp;
vector<int> par(200000);

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
    if (mp[ry].size() < mp[rx].size()) swap(rx, ry);
    if (rx == ry) {
        return 0;
    } else {
        return par[rx] = ry;
    }
}

map<int, int> num;

signed main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> C(N);
    rep(i, N) cin >> C[i];

    rep(i, N) C[i]--;

    init(N);

    rep(i, N) {
        mp[i][C[i]]++;
    }

    rep(_, Q) {
        int flag, s, t;
        cin >> flag >> s >> t;
        s--;
        t--;

        if (flag == 1) {
            if (root(s) == root(t)) {
                continue;
            }
            int rs = root(s);
            int rt = root(t);
            if (mp[rs].size() > mp[rt].size()) {
                for (auto [key, value] : mp[rt]) {
                    mp[rs][key] += value;
                    mp[rt][key] = 0;
                }
            } else {
                for (auto [key, value] : mp[rs]) {
                    mp[rt][key] += value;
                    mp[rs][key] = 0;
                }
            }
            unite(s, t);
        } else {
            cout << mp[root(s)][t] << endl;
        }
    }
}
