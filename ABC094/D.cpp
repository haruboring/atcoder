#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int n;
    cin >> n;
    vector<double> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    sort(all(a));
    double min_dis = 1000000000 + 1000;
    rep(i, n - 1) {
        min_dis = min(min_dis, abs(a[i] - a[n - 1] / 2));
    }
    int x;
    rep(i, n - 1) {
        if (abs(a[i] - a[n - 1] / 2) == min_dis) {
            x = a[i];
        }
    }

    cout << int(a[n - 1]) << " " << x << endl;
}