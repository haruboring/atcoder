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

    int ans = x / 11 * 2;
    if (x - ans * 11 / 2 > 6) {
        ans += 2;
    } else if (x - ans * 11 / 2 > 0) {
        ans++;
    }
    cout << ans << endl;
}
