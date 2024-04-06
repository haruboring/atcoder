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
    rep(i, N) {
        cin >> X[i] >> Y[i];
    }

    rep(i, N) {
        int ans = -1;
        int ma = -1;
        rep(j, N) {
            int dis = abs(X[i] - X[j]) * abs(X[i] - X[j]) + abs(Y[i] - Y[j]) * abs(Y[i] - Y[j]);

            if (ma < dis) {
                ma = dis;
                ans = j;
            }
        }

        cout << ans + 1 << endl;
    }
}
