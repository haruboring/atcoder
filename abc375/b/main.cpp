#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N;
    cin >> N;

    vector<int> X(N + 2), Y(N + 2);
    rep(i, N) cin >> X[i + 1] >> Y[i + 1];

    double ans = 0;
    rep(i, N + 1) ans += sqrt(pow(X[i + 1] - X[i], 2) + pow(Y[i + 1] - Y[i], 2));

    cout << fixed << setprecision(10) << ans << endl;
}
