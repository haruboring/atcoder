#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

ll pow10(ll n) {
    ll res = 1;
    rep(i, n) res *= 10;
    return res;
}

int main() {
    ll A, B, X;
    cin >> A >> B >> X;

    ll ans = 0;
    repp(i, 1, 19) {
        ll max_N = pow10(i) - 1;
        ll rest_X = X - B * (i);
        if ((rest_X / A) >= pow10(i - 1)) ans = max(ans, min(max_N, rest_X / A));
    }

    cout << min(1000000000LL, ans) << endl;
}