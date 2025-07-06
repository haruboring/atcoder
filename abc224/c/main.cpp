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
    vector<double> X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];

    int cnt = 0;
    rep(i, N) rep(j, N) rep(k, N) {
        double a = sqrt(powl(X[i] - X[j], 2) + powl(Y[i] - Y[j], 2));
        double b = sqrt(powl(X[j] - X[k], 2) + powl(Y[j] - Y[k], 2));
        double c = sqrt(powl(X[k] - X[i], 2) + powl(Y[k] - Y[i], 2));

        debug(powl(X[i] - X[j], 2));

        double s = (a + b + c) / 2;
        if ((s * (s - a) * (s - b) * (s - c)) < 0) continue;
        double S = sqrt(s * (s - a) * (s - b) * (s - c));

        if (abs(S) != 0) cnt++;
    }
    debug(cnt);
    cout << cnt / 6 << endl;
}
