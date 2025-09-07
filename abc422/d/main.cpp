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

    vector<int> T(21);
    T[0] = 1;
    rep(i, 20) T[i + 1] = T[i] * 2;

    int n = T[N];

    if (K % n == 0) {
        cout << 0 << endl;
    } else {
        cout << 1 << endl;
    }

    debug(n);
    int base = K / n;
    int ama = K % n;

    debug(base);

    vector<int> ans(n, base);

    for (int i = 20; i >= 0; i--) {
        if (T[i] > ama) continue;
        int nn = n / T[i];
        debug(nn);
        rep(j, n) {
            if (j % nn == 0) {
                ans[j + nn / 2]++;
                // debug(j + nn/2);
                ama--;
            }
        }
    }

    rep(i, n) cout << ans[i] << " ";
    cout << endl;
}
