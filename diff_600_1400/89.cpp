#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;

    vector<ll> ans(0);
    for (ll i = max(1LL, N - 9 * 18); i <= N; i++) {
        ll sum = i;
        ll tmp = i;
        while (tmp > 0) {
            sum += tmp % 10;
            tmp /= 10;
        }
        if (sum == N) ans.push_back(i);
    }

    cout << ans.size() << endl;
    for (ll a : ans) cout << a << endl;
}