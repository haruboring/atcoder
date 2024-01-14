#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, S, M, L;
    cin >> N >> S >> M >> L;

    int ans = 1e9;
    rep(i, 20) {
        rep(j, 20) {
            rep(k, 20) {
                if (i * 6 + j * 8 + k * 12 >= N) {
                    ans = min(ans, i * S + j * M + k * L);
                }
            }
        }
    }

    cout << ans << endl;
}
