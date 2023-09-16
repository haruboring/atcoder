#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    double N;
    cin >> N;
    double ans = 0;
    rep(i, N) {
        ans += (1 / N) * (i + 1) * (10000);
    }
    cout << ans << endl;
}