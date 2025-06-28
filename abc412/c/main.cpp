#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int T;
    cin >> T;
    rep(_, T) {
        int N;
        cin >> N;
        vector<int> S(N);
        rep(i, N) cin >> S[i];

        int cnt = 2;
        int s = S[0], g = S[N - 1];

        if (N == 2) {
            if (2 * s >= g) {
                cout << 2 << endl;
            } else {
                cout << -1 << endl;
            }

            continue;
        }

        vector<int> D(N - 1);
        rep(i, N - 2) D[i] = S[i + 1];
        D[N - 2] = 1e18;

        sort(all(D));

        if (2 * s >= g) {
            cout << 2 << endl;
            continue;
        }

        if (2 * s < D[0]) {
            cout << -1 << endl;
            continue;
        }

        while (2 * s < g) {
            int idx = upper_bound(all(D), 2 * s) - D.begin();
            if (s == D[idx - 1]) {
                cnt = -1;
                break;
            }
            s = D[idx - 1];

            cnt++;
        }

        cout << cnt << endl;
    }
}
