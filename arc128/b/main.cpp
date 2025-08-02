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
        int R, G, B;
        cin >> R >> G >> B;
        vector<int> T = {R, G, B};
        sort(all(T));
        R = T[0], G = T[1], B = T[2];
        if (R == G) {
            cout << R << endl;
        } else if (G == R) {
            cout << G << endl;
        } else {
            int cnt = 1e9;
            if ((G - R) % 3 == 0) {
                int t = (G - R) / 3 + R + 2 * (G - R) / 3;
                cnt = min(cnt, t);
            }
            if ((B - R) % 3 == 0) {
                int t = (B - R) / 3 + R + 2 * (B - R) / 3;
                cnt = min(cnt, t);
            }
            if ((B - G) % 3 == 0) {
                int t = (B - G) / 3 + G + 2 * (B - G) / 3;
                cnt = min(cnt, t);
            }
            if (cnt == 1e9) cnt = -1;
            cout << cnt << endl;
        }
    }
}
