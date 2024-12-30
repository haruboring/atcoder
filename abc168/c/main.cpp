#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int A, B, H, M;
    cin >> A >> B >> H >> M;

    double a = 30 * H + (double)30 * M / 60;
    double b = 6 * M;

    double d = a - b;

    double x = B * sin(M_PI * d / 180);
    double y = A - B * cos(M_PI * d / 180);

    cout << fixed << setprecision(20) << sqrt(x * x + y * y) << endl;
}
