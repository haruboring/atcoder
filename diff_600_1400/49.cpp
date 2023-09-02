#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> x(N), y(N);
    rep(i, N) cin >> x[i] >> y[i];

    set<int> sy;
    rep(i, N) {
        sy.insert(y[i]);
    }
    map<int, set<int>> mp;
    rep(i, N) {
        mp[y[i]].insert(x[i]);
    }

    ll ans = 0;
    for (auto y : sy) {
        for (auto other : sy) {
            if (y == other) continue;
            ll cnt = 0;
            for (auto x : mp[y]) {
                if (mp[other].count(x)) cnt++;
            }
            ans += (cnt) * (cnt - 1) / 2;
        }
    }

    cout << ans / 2 << endl;
}