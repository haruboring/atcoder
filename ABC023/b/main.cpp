#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    map<string, int> m;

    string ac = "b";
    m[ac] = 0;

    rep(i, 100) {
        if (ac.size() >= N) break;
        if (i % 3 == 0) {
            ac = "a" + ac + "c";
        } else if (i % 3 == 1) {
            ac = "c" + ac + "a";
        } else {
            ac = "b" + ac + "b";
        }
        m[ac] = i + 1;
    }

    if (m.count(S)){
        cout << m[S] << endl;
        return 0;
    }

    cout << -1 << endl;
}
