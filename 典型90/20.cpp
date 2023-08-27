#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;

    ll cb = 1;
    rep(i, b) cb *= c;

    if (a < cb)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}