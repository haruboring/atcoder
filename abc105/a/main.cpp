#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    vector<int> a(4);
    rep(i, 4) cin >> a[i];

    int sum = a[0] + a[1] + a[2] + a[3];
    rep(i, 4) {
        if (a[i] == sum - a[i]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    rep(i, 3) repp(j, i + 1, 4) {
        if (a[i] + a[j] == sum - a[i] - a[j]) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
}
