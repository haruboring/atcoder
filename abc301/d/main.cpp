#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

ll mypow(ll a, ll b) {
    ll an = 1;
    rep(i, b) {
        an *= a;
    }
    return an;
}

int main() {
    string S;
    cin >> S;
    reverse(all(S));
    ll N;
    cin >> N;
    vector<ll> hatena(0);
    ll base = 0;
    ll ma = 0;
    rep(i, S.size()) {
        if (S[i] == '?') {
            ma += (mypow(2, i)) * (ll)(1);
            hatena.push_back(i);
        } else {
            base += mypow(2, i) * (ll)(S[i] - '0');
        }
    }

    sort(all(hatena));
    ll size = hatena.size();

    if (base > N) {
        cout << -1 << endl;
        return 0;
    }
    if (base == N) {
        cout << base << endl;
        return 0;
    }
    if (base + ma <= N) {
        cout << base + ma << endl;
        return 0;
    }

    ll l = 0, r = (1LL << size) - 1;
    ll memo = base;
    rep(_, 100) {
        ll mid = (l + r) / 2;
        bitset<62> s(mid);
        ll sum = 0;
        rep(i, size) {
            if (s.test(i)) {
                sum += mypow(2, hatena[i]);
            }
        }
        if (sum + base > N) {
            r = mid;
        } else {
            l = mid;
            memo = sum + base;
        }
    }

    cout << memo << endl;
}