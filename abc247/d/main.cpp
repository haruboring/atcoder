#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int Q;
    cin >> Q;

    deque<pair<int, int>> d;
    rep(_, Q) {
        int f;
        cin >> f;
        if (f == 1) {
            int x, c;
            cin >> x >> c;
            d.push_back({x, c});
        } else {
            int c;
            cin >> c;

            int t = 0;
            while (c > 0) {
                auto [x, cc] = d.front();
                d.pop_front();
                if (c >= cc) {
                    c -= cc;
                    t += x * cc;
                } else {
                    d.push_front({x, cc - c});
                    t += x * c;
                    c = 0;
                }
            }

            cout << t << endl;
        }
    }
}
