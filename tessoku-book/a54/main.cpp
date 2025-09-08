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

    map<string, int> m;
    rep(i, Q) {
        int f;
        cin >> f;

        if (f == 1) {
            string x;
            int y;
            cin >> x >> y;

            m[x] = y;
        } else {
            string x;
            cin >> x;

            cout << m[x] << endl;
        }
    }
}
