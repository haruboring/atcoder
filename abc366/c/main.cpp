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

    multiset<int> ms;
    set<int> s;
    rep(_, Q) {
        int q;
        cin >> q;

        if (q == 3) {
            cout << s.size() << endl;
            continue;
        }

        int x;
        cin >> x;

        if (q == 1) {
            ms.insert(x);
            s.insert(x);
        }
        if (q == 2) {
            ms.erase(ms.find(x));
            if (ms.count(x) == 0) {
                s.erase(x);
            }
        }
    }
}
