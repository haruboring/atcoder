#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
using namespace std;
using ll = long long;

int main() {
    double N;
    cin >> N;
    ll size = sqrt(N) + 10;
    vector<ll> primes(0), all_num(size, 1);
    all_num[0] = 0, all_num[1] = 0;
    ll i = 2;
    while (i < size) {
        primes.push_back(i);
        for (ll j = i; j < size; j += i) {
            all_num[j] = 0;
        }
        while (1) {
            if (i >= size || all_num[i]) {
                break;
            } else {
                i++;
            }
        }
    }
    ll cnt = 0;
    rep(a_i, primes.size() - 2) {
        if (primes[a_i] > 1000) break;
        repp(b_i, a_i + 1, primes.size() - 1) {
            if (primes[b_i] > 10000) break;
            ll k = upper_bound(primes.begin(), primes.end(), sqrt(N / (primes[a_i] * primes[a_i] * primes[b_i]))) - primes.begin();
            // cout << "a=" << primes[a_i] << ", b=" << primes[b_i] << ", a_i=" << a_i << ", b_i=" << b_i << ", k=" << k << endl;
            cnt += max(k - b_i - 1, (ll)0);
        }
    }
    cout << cnt << endl;
}