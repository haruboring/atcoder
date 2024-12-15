#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int K;
    cin >> K;

    int ans = 0;
    repp(i, 1, K + 1) {
        repp(k, 1, K + 1) {
            if (i * k > K) break;
            ans += K / (i * k);
        }
    }

    cout << ans << endl;
}
