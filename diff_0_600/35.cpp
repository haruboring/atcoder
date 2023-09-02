#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    ll ans = 0;
    for (ll i = 1; i <= N; i++) {
        if (i % 3 != 0 && i % 5 != 0) {
            ans += i;
        }
    }

    cout << ans << endl;
}