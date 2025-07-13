#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int x;
    cin >> x;

    int cnt = 2 * (x / 11);
    x -= 11 * cnt / 2;
    debug(cnt);
    debug(x);
    while (x > 0) {
        if (cnt % 2 == 0) {
            x -= 6;
        } else {
            x -= 5;
        }
        cnt++;
    }

    cout << cnt << endl;
}
