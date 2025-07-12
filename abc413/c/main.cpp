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

    deque<pair<int, int>> q;
    rep(i, Q) {
        int f;
        cin >> f;

        if (f == 1) {
            int c, x;
            cin >> c >> x;
            q.push_back({x, c});
        } else {
            int k;
            cin >> k;
            int a = 0;
            while (k > 0) {
                auto [x, c] = q.front();
                q.pop_front();

                if (k >= c) {
                    a += x * c;
                    k -= c;
                } else {
                    q.push_front({x, c - k});
                    a += k * x;
                    k = 0;
                }
            }

            cout << a << endl;
        }
    }
}
