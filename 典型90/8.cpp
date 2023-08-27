#include "atcoder/all"
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
    string S;
    cin >> S;

    ll MOD = 1e9 + 7;

    vector<int> a(N), t(N), c(N), o(N), d(N), e(N), r(N);

    int cnt_a = 0;
    rep(i, N) {
        if (S[i] == 'a') cnt_a++;
        a[i] = cnt_a;
        cnt_a %= MOD;
    }

    int cnt_t = 0;
    rep(i, N) {
        if (S[i] == 't') cnt_t += a[i];
        t[i] = cnt_t;
        cnt_t %= MOD;
    }

    int cnt_c = 0;
    rep(i, N) {
        if (S[i] == 'c') cnt_c += t[i];
        c[i] = cnt_c;
        cnt_c %= MOD;
    }

    int cnt_o = 0;
    rep(i, N) {
        if (S[i] == 'o') cnt_o += c[i];
        o[i] = cnt_o;
        cnt_o %= MOD;
    }

    int cnt_d = 0;
    rep(i, N) {
        if (S[i] == 'd') cnt_d += o[i];
        d[i] = cnt_d;
        cnt_d %= MOD;
    }

    int cnt_e = 0;
    rep(i, N) {
        if (S[i] == 'e') cnt_e += d[i];
        e[i] = cnt_e;
        cnt_e %= MOD;
    }

    int cnt_r = 0;
    rep(i, N) {
        if (S[i] == 'r') cnt_r += e[i];
        r[i] = cnt_r;
        cnt_r %= MOD;
    }

    cout << r[N - 1] % MOD << endl;
}