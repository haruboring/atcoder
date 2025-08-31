#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int mod = 1000000007;
int fast_pow(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1) ret *= a;
        a = a * a % mod;
        ret %= mod;
        b >>= 1;
    }
    return ret;
}
signed main() {
    int a, b;
    cin >> a >> b;

    cout << fast_pow(a, b) << endl;
}
