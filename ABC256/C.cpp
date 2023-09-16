#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int h1, h2, h3, w1, w2, w3;
    cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;
    ll cnt = 0;
    repp(a, 1, h1 - 1) {
        repp(b, 1, h1 - a) {
            repp(c, 1, h1 - a - b + 1) {
                repp(d, 1, w1 - a) {
                    repp(g, 1, w1 - a - d + 1) {
                        repp(e, 1, h2 - d) {
                            if (w3 - c - h2 + d + e > 0 && a + b + c == h1 && d + e < h2 && g + w2 - b - e + w3 - c - h2 + d + e == h3) {
                                if (h3 - g - w2 + b + e > 0 && a + d + g == w1 && b + e < w2 && c + h2 - d - e + h3 - g - w2 + b + e == w3) {
                                    cnt++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << cnt << endl;
}