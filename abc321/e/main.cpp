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

    vector<int> bi(63);
    bi[0] = 1;
    repp(i, 1, 63) bi[i] = bi[i - 1] * 2;

    rep(_, T) {
        int N, X, K;
        cin >> N >> X >> K;

        int ans = 0;
        int x = X;
        int pre_x = -1;

        rep(j, K + 1) {
            if (x == 0) break;
            __int128_t l = x;
            bool no = false;
            rep(s, K - j) {
                l *= 2;
                if (j != 0 && s == 0 && l == pre_x) l++;
                if (l > (__int128_t)(N)) {
                    no = true;
                    break;
                }
            }
            if (no) {
                pre_x = x;
                x /= 2;
                continue;
            }
            int tmp = 1;
            if (K != 0 && j == 0) tmp *= 2;
            rep(s, K - j - 1) {
                tmp *= 2;
            }
            tmp = min(tmp, N - (int)l + 1);
            tmp = max(tmp, 0LL);
            ans += tmp;
            pre_x = x;
            x /= 2;
        }

        cout << ans << endl;
    }
}
