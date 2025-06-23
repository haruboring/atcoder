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

    double l = -1;
    rep(i, N) {
        rep(j, N) {
            l = max(l, sqrt((X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j])));
        }
    }

    cout << fixed << setprecision(10) << l << endl;
}
