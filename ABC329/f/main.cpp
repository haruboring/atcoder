#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> C(N);
    rep(i, N) cin >> C[i];

    vector<set<int>> sv(N);
    rep(i, N) {
        sv[i].insert(C[i]);
    }
    map<int, int> mp;
    rep(i, N) mp[i] = i;
    rep(_, Q) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        int a_size = sv[mp[a]].size();
        int b_size = sv[mp[b]].size();
        if (a_size < b_size) {
            sv[mp[b]].insert(all(sv[mp[a]]));
            sv[mp[a]].clear();
        } else {
            sv[mp[a]].insert(all(sv[mp[b]]));
            sv[mp[b]].clear();
            swap(mp[a], mp[b]);
        }
        cout << sv[mp[b]].size() << endl;
    }
}
