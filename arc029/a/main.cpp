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
    vector<int> T(N);
    rep(i, N) cin >> T[i];

    int ans = 1e18;
    rep(i, (1 << N)) {
        bitset<4> s(i);
        int a = 0, b = 0;
        rep(j, N) {
            if (s.test(j)) {
                a += T[j];
            } else {
                b += T[j];
            }
        }

        ans = min(ans, max(a, b));
    }
    cout << ans << endl;
}
