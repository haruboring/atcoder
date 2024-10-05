// #include "atcoder/all"
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
    vector<int> x(N), y(N);
    rep(i, N) cin >> x[i] >> y[i];
    vector<int> z(M);
    rep(i, M) cin >> z[i];

    sort(all(z));
    map<int, set<int>> st, ed;
    rep(i, N) st[x[i]].insert(i);
    rep(i, N) ed[y[i]].insert(i);
    map<int, int> i2e;
    rep(i, N) i2e[i] = y[i];

    set<int> al;
    rep(i, N) {
        al.insert(x[i]);
        al.insert(y[i]);
    }
    rep(i, M) al.insert(z[i]);
    map<int, set<int>> user;
    rep(i, M) user[z[i]].insert(i);

    multiset<int> ends;
    int cnt = 0;
    for (auto t : al) {
        for (auto i : st[t]) {
            ends.insert(i2e[i]);
        }
                for (auto i : user[t]) {
            if (ends.size() == 0) continue;
            int mi = *begin(ends);
            cnt++;
            ends.erase(ends.find(mi));
        }
        for (auto i : ed[t]) {
            if(ends.count(i2e[i]) == 0) continue;
            ends.erase(ends.find(i2e[i]));
        }

    }
    cout << cnt << endl;
}