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
    vector<int> v(0);
    rep(i, Q) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            v.push_back(x);
        } else {
            cout << v[v.size() - 1 - (x - 1)] << endl;
        }
    }
}
