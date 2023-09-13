#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, X, Y;
    cin >> N >> X >> Y;
    vector<int> P(N - 1), T(N - 1);
    rep(i, N - 1) cin >> P[i] >> T[i];
    int Q;
    cin >> Q;
    vector<int> q(Q);
    rep(i, Q) cin >> q[i];

    vector<int> cost(3 * 5 * 7 * 8);
    repp(i, 1, 3 * 5 * 7 * 8 + 1) {
        int tmp = i;

        for (int j = 0; j < N - 1; j++) {
            if (tmp % P[j] == 0) {
                tmp += T[j];
            } else {
                tmp += (P[j] - tmp % P[j]) + T[j];
            }
        }

        cost[i % (3 * 5 * 7 * 8)] = tmp - i;
    }

    rep(i, Q) {
        int ans = q[i];
        ans += X;
        ans += cost[ans % (3 * 5 * 7 * 8)];
        ans += Y;

        cout << ans << endl;
    }
}