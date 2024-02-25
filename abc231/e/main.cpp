#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

map<pair<int, int>, int> dp;
vector<int> v(64);
int n, x;

int f(int x, int i) {
    if (i == n - 1)
        return x / v[i];
    if (dp.count({x, i}))
        return dp[{x, i}];

    return dp[{x, i}] = min(f(x - x % v[i + 1], i + 1) + (x % v[i + 1]) / v[i],
                            f(x - x % v[i + 1] + v[i + 1], i + 1) + (v[i + 1] - x % v[i + 1]) / v[i]);
}

signed main() {
    cin >> n >> x;
    rep(i, n) cin >> v[i];

    cout << f(x, 0) << endl;
}