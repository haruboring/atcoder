#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, K;
    cin >> N >> K;
    vector<int> X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];
    sort(all(X));
    sort(all(Y));

    int l = -1, r = 1e9 + 100;
    while (r - l > 1) {
        int m = (l + r) / 2;

        vector<int> addX(N), addY(N);
        rep(i, N) {
            addX[i] = X[i] - m;
            addY[i] = Y[i] - m;
        }

        vector<int> xx, yy;
        merge(all(X), all(addX), back_inserter(xx));
        merge(all(Y), all(addY), back_inserter(yy));
        int xl = xx[N], yl = yy[N];

        int cost = 0;
        rep(i, N) {
            if (xl <= X[i] && X[i] <= xl + m && yl <= Y[i] && Y[i] <= yl + m) continue;
            if (X[i] < xl) {
                cost += xl - X[i];
            } else if (xl + m < X[i]) {
                cost += X[i] - (xl + m);
            }
            if (Y[i] < yl) {
                cost += yl - Y[i];
            } else if (yl + m < Y[i]) {
                cost += Y[i] - (yl + m);
            }
        }

        if (cost > K) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << r << endl;
}
