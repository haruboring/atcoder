#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    vector<ll> F(N), S(N);
    rep(i, N) cin >> F[i] >> S[i];

    ll ans = -1;

    map<ll, multiset<ll>> mp;
    set<ll> f;
    rep(i, N) {
        mp[F[i]].insert(S[i]);
        f.insert(F[i]);
    }

    for (auto ff : f) {
        if (mp[ff].size() < 2) continue;
        ll tmp = *mp[ff].rbegin();
        mp[ff].erase(mp[ff].find(tmp));
        ans = max(ans, tmp + *mp[ff].rbegin() / 2);
        mp[ff].insert(tmp);
    }

    multiset<ll> s;
    rep(i, N) s.insert(S[i]);

    for (auto ff : f) {
        ll tmp = *mp[ff].rbegin();
        for (auto a : mp[ff]) {
            s.erase(s.find(a));
        }
        if (s.size() != 0 && tmp >= *s.rbegin()) ans = max(ans, tmp + *s.rbegin());

        for (auto a : mp[ff]) {
            s.insert(a);
        }
    }

    cout << ans << endl;
}