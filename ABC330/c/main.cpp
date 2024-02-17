#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int D;
    cin >> D;

    int ans = 1e18;
    repp(x, 1, 1e7) {
        int y2 = abs(D - x * x);
        int y = sqrt(y2);

        ans = min(ans, abs(D - x * x - y * y));
        y--;
        ans = min(ans, abs(D - x * x - y * y));
        y += 2;
        ans = min(ans, abs(D - x * x - y * y));
    }

    cout << ans << endl;
}
