#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    set<int> s;
    multiset<int> ms;
    rep(i, 4) {
        int a;
        cin >> a;
        s.insert(a);
        ms.insert(a);
    }

    if (s.size() != 2) {
        cout << "No" << endl;
        return 0;
    }

    int a = *s.begin(), b = *s.rbegin();
    if ((ms.count(a) == 2 && ms.count(b) == 2) || (ms.count(a) == 3 && ms.count(b) == 1) || (ms.count(a) == 1 && ms.count(b) == 3)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
