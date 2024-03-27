#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int A, B, C;
    cin >> A >> B >> C;

    map<tuple<int, int, int>, double> dp;
    dp[make_tuple(A, B, C)] = 1;
    repp(i, A + B + C, 300) {
        rep(a, 100) {
            rep(b, 100) {
                int c = i - a - b;
                if (c < 0) continue;
                if (c >= 100) continue;

                double p = dp[make_tuple(a, b, c)];
                p *= (double)a / (a + b + c);
                dp[make_tuple(a + 1, b, c)] += p;
                p = dp[make_tuple(a, b, c)];
                p *=(double)b / (a + b + c);
                dp[make_tuple(a, b + 1, c)] += p;
                p = dp[make_tuple(a, b, c)];
                p *=(double)c / (a + b + c);
                dp[make_tuple(a, b, c + 1)] += p;
            }
        }
    }

    double ans = 0;
    rep(a, 100) {
        rep(b, 100) {
            int c = 100;

            ans += dp[make_tuple(a, b, c)] * (a + b + c - A - B - C);
        }
    }
    rep(b, 100) {
        rep(c, 100) {
            int a = 100;

            ans += dp[make_tuple(a, b, c)] * (a + b + c - A - B - C);
        }
    }
    rep(c, 100) {
        rep(a, 100) {
            int b = 100;

            ans += dp[make_tuple(a, b, c)] * (a + b + c - A - B - C);
        }
    }

    cout << fixed << setprecision(10) << ans << endl;
}
