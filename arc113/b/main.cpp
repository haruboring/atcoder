#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int mod_pow(int x, int n, const int p) {
    int ret = 1;
    while (n > 0) {
        if (n & 1) (ret *= x) %= p;
        (x *= x) %= p;
        n >>= 1;
    }
    return ret;
}

signed main() {
    int A, B, C;
    cin >> A >> B >> C;

    int mi = 0;
    int tmp = (A % 10) * (A % 10) % 10;
    rep(i, 100) {
        if (tmp == A % 10) {
            mi = i + 1;
            break;
        }
        tmp *= A;
        tmp %= 10;
    }

    debug(mi);

    int bc = mod_pow(B, C, mi);
    if (bc == 0) bc = mi;
    debug(bc);
    cout << mod_pow(A, bc, 10) % 10 << endl;
}
