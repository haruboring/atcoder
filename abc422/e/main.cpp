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
    vector<int> X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];

    mt19937_64 rng(58);

    rep(_, 100) {
        int i = rand() % N;
        int j = rand() % N;
        while (i == j) {
            j = rand() % N;
        }
        int x = X[i], y = Y[i];
        int gcd_ = gcd((Y[j] - Y[i]), (X[j] - X[i]));
        int ch = (Y[j] - Y[i]) / gcd_;
        int mo = (X[j] - X[i]) / gcd_;

        int a = ch, b = -mo, c = mo * Y[i] - ch * X[i];
        int cnt = 0;
        rep(k, N) if (X[k] * a + Y[k] * b + c == 0) cnt++;

        if (cnt > N / 2) {
            cout << "Yes" << endl;
            cout << ch << " " << -mo << " " << mo * y - ch * x << endl;
            return 0;
        }
    }

    cout << "No" << endl;
}
