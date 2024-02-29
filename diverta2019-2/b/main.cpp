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
    vector<int> x(N), y(N);
    rep(i, N) cin >> x[i] >> y[i];

    if (N == 1) {
        cout << 1 << endl;
        return 0;
    }

    int ans = 1e9;
    rep(i, N) {
        rep(j, N) {
            if (i == j) continue;
            int dx = x[i] - x[j];
            int dy = y[i] - y[j];
            int cnt = 0;
            rep(k, N) {
                rep(l, N) {
                    if (k == l) continue;
                    if (x[k] - x[l] == dx && y[k] - y[l] == dy) {
                        cnt++;
                    }
                }
            }
            ans = min(ans, N - cnt);
        }
    }
    cout << ans << endl;
}
