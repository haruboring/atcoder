#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int R;
    cin >> R;

    int cnt = 0;
    for (int x = 0; x <= 1000000; x++) {
        int l = -1, r = 1e9;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if ((pow(x + 0.5, 2) + pow(m + 0.5, 2) <= pow(R, 2)) && (pow(x + 0.5, 2) + pow(m - 0.5, 2) <= pow(R, 2)) && (pow(x - 0.5, 2) + pow(m + 0.5, 2) <= pow(R, 2)) && (pow(x - 0.5, 2) + pow(m - 0.5, 2) <= pow(R, 2))) {
                l = m;
            } else {
                r = m;
            }
        }

        if (l == -1) continue;
        if (x == 0) cnt++;
        cnt += l * 4;
    }

    cout << cnt << endl;
}
