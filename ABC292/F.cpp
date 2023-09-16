#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    double A, B;
    cin >> A >> B;

    // A<=B
    if (A > B) swap(A, B);

    if (3 * B * B >= 4 * A * A) {
        cout << setprecision(20) << 2 * A / sqrt(3) << endl;
        return 0;
    }
    cout << setprecision(20) << B / cos(atan(2 * A / B - sqrt(3))) << endl;
}