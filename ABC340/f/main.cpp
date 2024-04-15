#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

// 拡張ユークリッドの互除法
// ax+by=gcd(a,b) となる整数の組 (x,y) を O(logmin(∣a∣,∣b∣)) で計算
pair<int, int> extgcd(int a, int b) {
    if (b == 0) return {1, 0};
    auto [y, x] = extgcd(b, a % b);
    y -= a / b * x;
    return {x, y};
}

signed main() {
    debug(gcd(-2,-2));
    int X, Y;
    cin >> X >> Y;

    int g = gcd(X, Y);
    if (g > 2) {
        cout << -1 << endl;
        return 0;
    }

    auto [A, B] = extgcd(Y, -X);
    cout << 2 * A / g << " " << 2 * B / g << endl;
}
