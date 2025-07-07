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
    rep(i, N - 2) repp(j, i + 1, N - 1) repp(k, j + 1, N) {
        int xi = X[i], yi = Y[i], xj = X[j], yj = Y[j], xk = X[k], yk = Y[k];
        xj -= xi, yj -= yi, xk -= xi, yk -= yi, xi = 0, yi = 0;

        if (xj == 0 && xk == 0) continue;
        if (yj == 0 && yk == 0) continue;

        if (xj * yk != yj * xk) cnt++;
    }
    cout << cnt << endl;
}
