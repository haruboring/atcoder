#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;

    multiset<ll> s;

    ll copyN = N;
    for (ll i = 2; i * i <= N; i++) {
        while (copyN % i == 0) {
            s.insert(i);
            copyN /= i;
        }
    }
    if (copyN != 1) s.insert(copyN);

    ll tmp = 0;
    ll ans = 0;
    debug(s.size());
    while (tmp < s.size() - 1) {
        tmp += pow(2, ans);
        ans++;
    }

    cout << ans << endl;
}
