#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    set<string> s;
    rep(i, 4) {
        string ss;
        cin >> ss;
        s.insert(ss);
    }

    if (s.size() == 4) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
