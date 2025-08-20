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
    rep(i, N - 2) {
        repp(j, i + 1, N - 1) {
            repp(k, j + 1, N) {
                int xa = X[i], ya = Y[i], xb = X[j], yb = Y[j], xc = X[k], yc = Y[k];
                xb -= xa, yb -= ya, xc -= xa, yc -= ya;

                if (abs(xb * yc - xc * yb) != 0 && abs(xb * yc - xc * yb) % 2 == 0) cnt++;
            }
        }
    }
    cout << cnt << endl;
}
