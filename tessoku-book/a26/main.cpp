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
    vector<int> X(Q);
    rep(i, Q) cin >> X[i];

    rep(i, Q) {
        int x = X[i];
        bool p = true;
        for (int j = 2; j * j <= X[i]; j++) {
            if (x % j == 0) p = false;
        }
        if (p) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
