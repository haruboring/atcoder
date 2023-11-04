#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int llpow(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

signed main() {
    int B;
    cin >> B;

    repp(i, 1, 16) {
        if (llpow(i, i) == B) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}