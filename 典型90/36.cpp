#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> x(N), y(N);
    rep(i, N) cin >> x[i] >> y[i];
    vector<int> q(Q);
    rep(i, Q) cin >> q[i];

    rep(i, Q) q[i]--;

    vector<int> X(N), Y(N), cX(N), cY(N);
    rep(i, N) {
        X[i] = x[i] + y[i];
        Y[i] = x[i] - y[i];
    }
    cX = X;
    cY = Y;

    sort(all(X));
    sort(all(Y));

    for (int i = 0; i < Q; i++) {
        int ans = max(abs(X[0] - cX[q[i]]), abs(X[N - 1] - cX[q[i]]));
        ans = max(ans, abs(Y[0] - cY[q[i]]));
        ans = max(ans, abs(Y[N - 1] - cY[q[i]]));
        cout << ans << endl;
    }
}