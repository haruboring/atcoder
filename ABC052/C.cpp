#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N;
    cin >> N;

    int MOD = 1000000007;

    map<int, int> primes;
    repp(i, 2, N + 1) {
        int tmp = i;
        for (int j = 2; j * j <= i; j++) {
            while (tmp % j == 0) {
                primes[j]++;
                tmp /= j;
            }
        }
        if (tmp != 1) {
            primes[tmp]++;
        }
    }

    int ans = 1;
    for (auto [p, cnt] : primes) {
        debug(p);

        ans *= (cnt + 1);
        ans %= MOD;
    }

    cout << ans << endl;
}