#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int n, X;
    cin >> n >> X;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    int sum = 0;
    rep(i, n) {
        if (((1 << i) & X) != 0) {
            sum += a[i];
        }
    }
    cout << sum << endl;
}