// #include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

// O(NloglogN)
vector<bool> Eratosthenes(int N) {
    // テーブル
    vector<bool> isprime(N + 1, true);

    // 0, 1 は予めふるい落としておく
    isprime[0] = isprime[1] = false;

    // ふるい
    for (int p = 2; p <= N; ++p) {
        // すでに合成数であるものはスキップする
        if (!isprime[p]) continue;

        // p 以外の p の倍数から素数ラベルを剥奪
        for (int q = p * 2; q <= N; q += p) {
            isprime[q] = false;
        }
    }

    // 1 以上 N 以下の整数が素数かどうか
    return isprime;
}

signed main() {
    int N;
    cin >> N;

    vector<bool> isprime = Eratosthenes(1000000 + 100);
    vector<int> primes;
    set<int> sp;
    int max_b = -1;
    repp(i, 2, 1000000 + 100) {
        if (isprime[i]) {
            if (max_b == -1 && i > 1e4 + 10) max_b = i;
            primes.push_back(i);
            sp.insert(i);
        }
    }

    int ans = 0;
    rep(i, max_b) {
        for (int j = i + 1; primes[i] * primes[i] * primes[j] * primes[j] * primes[j] <= N; j++) {
            int p = primes[i] * primes[i] * primes[j];
            int itr = upper_bound(all(primes), sqrt(N / p)) - primes.begin();
            ans += max(0LL, (itr - 1) - j);
        }
    }

    cout << ans << endl;
}