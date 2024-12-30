#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int D, N;
    cin >> D >> N;

    if (D == 0) {
        int ans = 0;
        while (N) {
            ans += 1;
            if (ans % 100 != 0) N--;
        }

        cout << ans << endl;
        return 0;
    }
    if (D == 2) {
        int ans = 0;
        while (N) {
            ans += 10000;
            if (ans % 1000000 != 0) N--;
        }

        cout << ans << endl;
        return 0;
    }

    int ans = 0;
    while (N) {
        ans += 100;
        if (ans % 10000 != 0) N--;
    }

    cout << ans << endl;
}
