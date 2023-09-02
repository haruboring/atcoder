#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    ll H;
    cin >> H;

    ll cnt = 0;
    while (H >= 1) {
        H /= 2;
        cnt++;
    }

    ll ans = 0;
    rep(i, cnt) {
        ans += pow(2, i);
    }

    cout << ans << endl;
}
