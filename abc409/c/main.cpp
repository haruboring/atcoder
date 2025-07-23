#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, L;
    cin >> N >> L;
    vector<int> D(N - 1);
    rep(i, N - 1) cin >> D[i];

    if (L % 3) {
        cout << 0 << endl;
        return 0;
    }

    map<int, int> m;
    int t = 0;
    m[t]++;
    rep(i, N - 1) {
        t += D[i];
        t %= L;
        m[t]++;
    }

    int ans = 0;
    for (auto [a, cnt] : m) {
        cnt *= m[(a + L / 3) % L] * m[(a + 2 * L / 3) % L];
        ans += cnt;
    }

    debug(ans);
    cout << ans / 3 << endl;
}
