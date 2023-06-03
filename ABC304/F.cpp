#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    string S;
    cin >> S;
    ll BASE = 998244353;

    vector<ll> yakusu(0);
    repp(i, 1, sqrt(N) + 1) {
        if (N % i == 0) {
            yakusu.push_back(i);
            if (i != N / i) yakusu.push_back(N / i);
        }
    }

    sort(all(yakusu));

    vector<ll> must_work(0);
    rep(i, N) {
        if (S[i] == '.') {
            must_work.push_back(i);
        }
    }
    ll ans = 0;
    vector<ll> temps(0);

    rep(i, yakusu.size()) {
        ll yaku = yakusu[i];
        if (yaku == N) continue;
        ll tmp = 1;
        set<ll> s;
        rep(j, must_work.size()) {
            s.insert(must_work[j] % yaku);
        }
        ll tmp2 = s.size();
        rep(j, yaku - tmp2) {
            tmp *= 2;
            tmp %= BASE;
        }

        rep(j, i) {
            if (yakusu[i] % yakusu[j] == 0) {
                tmp -= temps[j];
            }
        }
        tmp = ((tmp % BASE) + BASE) % BASE;
        temps.push_back(tmp);
        ans += tmp;
        ans %= BASE;
    }

    cout << ans << endl;
}