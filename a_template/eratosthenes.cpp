#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

// 1 以上 N 以下の整数が素数かどうかを返す
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