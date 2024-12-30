// #include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    vector<int> a(3);
    rep(i, 3) cin >> a[i];

    sort(all(a));
    if (a[0] + a[1] == a[2]) {
        cout << "Yes" << endl;
    } else if (a[0] == a[2]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}