#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll A, B, C;
    cin >> A >> B >> C;

    ll size = gcd(gcd(A, B), C);

    cout << A / size + B / size + C / size - 3 << endl;
}