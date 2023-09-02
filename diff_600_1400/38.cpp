#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
using namespace std;
using ll = long long;

vector<bool> IsPrime;

void sieve(size_t max) {
    if (max + 1 > IsPrime.size()) {     // resizeで要素数が減らないように
        IsPrime.resize(max + 1, true);  // IsPrimeに必要な要素数を確保
    }
    IsPrime[0] = false;  // 0は素数ではない
    IsPrime[1] = false;  // 1は素数ではない

    for (size_t i = 2; i * i <= max; ++i)          // 0からsqrt(max)まで調べる
        if (IsPrime[i])                            // iが素数ならば
            for (size_t j = 2; i * j <= max; ++j)  // (max以下の)iの倍数は
                IsPrime[i * j] = false;            // 素数ではない
}

int main() {
    ll N;
    cin >> N;

    sieve(1000000 + 100);
    vector<ll> primes;
    rep(i, 1000000 + 100) {
        if (IsPrime[i]) primes.push_back(i);
    }

    ll ans = 0;

    repp(i, 1, primes.size()) {
        ll p = primes[i];
        ll tmp = p * p * p;
        ll max_p = N / tmp;
        ll ind = upper_bound(all(primes), max_p) - primes.begin();
        // cout << "p=" << p << ", max_p=" << max_p << ", ind=" << ind << endl;
        ans += min(ind, i);
    }

    cout << ans << endl;
}