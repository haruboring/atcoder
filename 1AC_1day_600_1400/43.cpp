#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<double> st(N);

    rep(i, N) {
        if (i == 0) {
            st[i] = 1;
        } else if (i == 1) {
            st[i] = 4;
        } else if (i < 5) {
            st[i] = 5;
        } else {
            st[i] = 6;
        }
    }
    reverse(all(st));

    double ans = 0;
    double base = 1;
    rep(i, N) {
        ans += (base * (double)(7 - st[i]) / 6) * (6 + st[i]) / 2;
        base *= (double)(st[i] - 1) / 6;
    }

    cout << fixed << setprecision(10) << ans << endl;
}