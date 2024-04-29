#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int N, A;
double X, Y;
map<int, double> mp;
double f(int x) {
    if (mp.count(x)) return mp[x];
    double b = 6 * Y / 5 + f(x / 2) / 5 + f(x / 3) / 5 + f(x / 4) / 5 + f(x / 5) / 5 + f(x / 6) / 5;
    double a = X + f(x / A);
    return mp[x] = min(a, b);
}

signed main() {
    cin >> N >> A >> X >> Y;

    mp[0] = 0;
    double ans = f(N);

    cout << fixed << setprecision(19) << ans << endl;
}
