#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int L, Q;
    cin >> L >> Q;

    set<int> s, rs;
    s.insert(0);
    s.insert(L);
    rs.insert(0);
    rs.insert(-L);
    rep(i, Q) {
        int c, x;
        cin >> c >> x;
        if (c == 1) {
            s.insert(x);
            rs.insert(-x);
        } else {
            int s_ = *s.lower_bound(x);
            int rs_ = -*rs.lower_bound(-x);
            cout << s_ - rs_ << endl;
        }
    }
}
