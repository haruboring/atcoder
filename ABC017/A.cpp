#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int s1, e1, s2, e2, s3, e3;
    cin >> s1 >> e1 >> s2 >> e2 >> s3 >> e3;
    int ans = s1 * e1 + s2 * e2 + s3 * e3;
    ans /= 10;
    cout << ans << endl;
}