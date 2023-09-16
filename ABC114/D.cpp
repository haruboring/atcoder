#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    ll N;
    cin >> N;
    vector<ll> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

    map<int, int> soinsu;
    repp(i, 1, N + 1) {
        int copy_i = i;
        for (int prime : primes) {
            while (copy_i % prime == 0) {
                soinsu[prime]++;
                copy_i /= prime;
            }
        }
    }

    ll ans = 0;
    rep(i, 25) {
        rep(j, 25) {
            rep(k, 25) {
                if (i == j || j == k || k == i) continue;
                if (soinsu[primes[i]] > 1 && soinsu[primes[j]] > 3 && soinsu[primes[k]] > 3) {
                    ans++;
                }
            }
        }
    }
    ans /= 2;
    rep(i, 25) {
        rep(j, 25) {
            if (i == j) continue;
            if (soinsu[primes[i]] > 1 && soinsu[primes[j]] > 23) {
                ans++;
            }
            if (soinsu[primes[i]] > 3 && soinsu[primes[j]] > 13) {
                ans++;
            }
        }
    }
    rep(i, 25) {
        if (soinsu[primes[i]] > 73) {
            ans++;
        }
    }

    cout << ans << endl;
}