#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int get_v2(int a, int b) {
    int ans = 0;
    if (a % 4 == 0) {
        ans += a * b;
    } else if (a % 4 == 1) {
        ans += (a / 4) * b * 4;
        ans += (b / 2) * 3;
        if (b % 2 == 1) ans += 2;

    } else if (a % 4 == 2) {
        ans += (a / 4) * b * 4;
        ans += (b / 2) * 6;
        if (b % 2 == 1) ans += 3;

    } else {
        ans += (a / 4) * b * 4;
        ans += (b / 2) * 7;
        if (b % 2 == 1) ans += 3;
    }

    return ans;
}

signed main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int d = 4000000000000;
    A += d, B += d, C += d, D += d;
    int cA = A, cB = B;
    A -= (cA / 4) * 4;
    B -= (cB / 4) * 4;
    C -= (cA / 4) * 4;
    D -= (cB / 4) * 4;

    debug(A), debug(B), debug(C), debug(D);

    int ans = get_v2(C, D);
    ans -= get_v2(A, D);
    ans -= get_v2(C, B);
    ans += get_v2(A, B);

    cout << ans << endl;
}
