#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

ll BASE = 998244353;

int main() {
    ll N;
    cin >> N;
    ll keta = 1;
    ll sum = 0;
    while (keta <= N) {
        ll s = keta * 10 - keta;
        if (N < keta * 10) {
            s = N - keta + 1;
        }
        sum += ((((1 + s) % BASE) * (s % BASE)) / 2) % BASE;
        keta *= 10;
    }
    cout << sum % BASE << endl;
}