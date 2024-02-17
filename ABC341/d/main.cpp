#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M, K;
    cin >> N >> M >> K;

    int l = 0, r = 4e18 + 10000;
    int ma = gcd(N, M);
    ma = N * M / ma;
    while (r - l > 1) {
        int m = (l + r) / 2;
        int cnt = m / N + m / M - m / ma - m / ma;
        if (cnt >= K) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << r << endl;
}
