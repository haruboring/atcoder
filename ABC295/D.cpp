#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    string S;
    cin >> S;
    set<char> all = {};
    rep(i, S.size()) {
        if (all.count(S[i])) {
            all.erase(S[i]);
        } else {
            all.insert(S[i]);
        }
    }
    set<char> l = all, r = all;
    map<set<char>, set<int>> m;
    m[all].insert(0);
    rep(i, S.size()) {
        if (l.count(S[i])) {
            l.erase(S[i]);
        } else {
            l.insert(S[i]);
        }
        m[l].insert(i + 1);
    }

    ll ans = 0;
    for (auto a : m) {
        ll s = a.second.size();
        ans += (s) * (s - 1) / 2;
    }
    cout << ans << endl;
}
