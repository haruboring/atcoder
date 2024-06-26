#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int L;
    cin >> L;

    // (L-1) C (11)
    __int128_t ans = 1;

    for (int i = L - 1; i > L - 12; i--) {
        ans *= i;
    }
    rep(i, 11) {
        ans /= i + 1;
    }

    cout << (int)ans << endl;
}
