#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

vector<int> par(200000 + 100);

void init(int n) {
    rep(i, n) par[i] = i;
}

int root(int x) {
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
}

int unite(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if (ry < rx) swap(rx, ry);
    if (rx == ry) {
        return 0;
    } else {
        return par[rx] = ry;
    }
}

signed main() {
    int N;
    cin >> N;
    vector<int> P(N), Q(N);
    rep(i, N) cin >> P[i];
    rep(i, N) cin >> Q[i];

    init(N);
    rep(i, N) {
        P[i]--;
        Q[i]--;
        unite(P[i], Q[i]);
    }

    map<int, int> mp;
    rep(i, N) {
        mp[root(i)]++;
    }

    vector<int> dp(N + 10);
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 4;
    repp(i, 4, N + 1) {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= 998244353;
    }

    int ans = 1;
    for (auto [k, v] : mp) {
        ans *= dp[v];
        ans %= 998244353;
    }

    cout << ans << endl;
}