#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    map<int, int> m;
    set<int> s;

    rep(i, 3) {
        int x;
        cin >> x;
        m[x]++;
        s.insert(x);
    }

    if (s.size() == 2) {
        for (auto [k, c] : m) {
            if (c == 1) {
                cout << k << endl;
                return 0;
            }
        }
    } else if (s.size() == 1) {
        for (auto [k, c] : m) {
            cout << k << endl;
            return 0;
        }
    }

    cout << 0 << endl;
}
