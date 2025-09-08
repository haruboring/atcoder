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

    set<int> s;
    s.insert(1e18);
    rep(i, Q) {
        int f;
        cin >> f;

        if (f == 1) {
            int x;
            cin >> x;

            s.insert(x);
        } else if (f == 2) {
            int x;
            cin >> x;

            s.erase(x);
        } else {
            int x;
            cin >> x;

            int a = *s.lower_bound(x);
            if (a == 1e18) a = -1;
            cout << a << endl;
        }
    }
}
