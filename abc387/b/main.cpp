#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int X;
    cin >> X;

    int ans = 0;
    repp(i, 1, 10) {
        repp(j, 1, 10) {
            if (i * j != X) ans += i * j;
        }
    }

    cout << ans << endl;
}
