// #include "atcoder/all"
#include "bits/stdc++.h"
// #define int long long
#define a(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    debug(15 * 15 * 15 * 29 * 29 * 29);
    int V1, V2, V3;
    cin >> V1 >> V2 >> V3;

    // (a1,a2,a3) = (0,0,0)

    repp(a2, -7, 8) {
        repp(b2, -7, 8) {
            repp(c2, -7, 8) {
                repp(a3, -14, 15) {
                    repp(b3, -14, 15) {
                        repp(c3, -14, 15) {
                            int la = max({a2, a3});
                            int lb = max({0, b2, b3});
                            int lc = max({0, c2, c3});
                            int ra = min({7, a2 + 7, a3 + 7});
                            int rb = min({7, b2 + 7, b3 + 7});
                            int rc = min({7, c2 + 7, c3 + 7});
                            int v3 = max(0, ra - la) * max(0, rb - lb) * max(0, rc - lc);

                            int v2 = 0;
                            // 1 and 2
                            la = max(0, a2);
                            lb = max(0, b2);
                            lc = max(0, c2);
                            ra = min(7, a2 + 7);
                            rb = min(7, b2 + 7);
                            rc = min(7, c2 + 7);
                            v2 += max(0, ra - la) * max(0, rb - lb) * max(0, rc - lc);
                            // 1 and 3
                            la = max(0, a3);
                            lb = max(0, b3);
                            lc = max(0, c3);
                            ra = min(7, a3 + 7);
                            rb = min(7, b3 + 7);
                            rc = min(7, c3 + 7);
                            v2 += max(0, ra - la) * max(0, rb - lb) * max(0, rc - lc);
                            // 2 and 3
                            la = max(a2, a3);
                            lb = max(b2, b3);
                            lc = max(c2, c3);
                            ra = min(a2 + 7, a3 + 7);
                            rb = min(b2 + 7, b3 + 7);
                            rc = min(c2 + 7, c3 + 7);
                            v2 += max(0, ra - la) * max(0, rb - lb) * max(0, rc - lc);
                            v2 -= 3 * v3;
                            int v1 = 7 * 7 * 7 * 3 - 2 * v2 - 3 * v3;

                            // debug(v1);
                            // debug(v2);
                            // debug(v3);

                            if (v1 == V1 && v2 == V2 && v3 == V3) {
                                cout << "Yes" << endl;
                                cout << 0 << " " << 0 << " " << 0 << " ";
                                cout << a2 << " " << b2 << " " << c2 << " ";
                                cout << a3 << " " << b3 << " " << c3 << endl;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << "No" << endl;
}
