#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int N, K, D;
vector<vector<vector<ll>>> dp(110, vector<vector<ll>>(110, vector<ll>(110, -1)));
vector<ll> a(0);
ll max_D = -1;

void f(int i, int j) {
    if (i < 0 || i > N || j < 0 || j > K) {
        return;
    }
    rep(d, D) {
        // 使わない
        dp[i + 1][j][d] = max(dp[i + 1][j][d], dp[i][j][d]);
        // 使う
        if (dp[i][j][d] != -1) {
            dp[i + 1][j + 1][(d + a[i]) % D] = max(dp[i + 1][j + 1][(d + a[i]) % D], dp[i][j][d] + a[i]);
        }
    }
}
int main() {
    cin >> N >> K >> D;
    rep(i, N) {
        ll ai;
        cin >> ai;
        a.push_back(ai);
    }
    dp[0][0][0] = 0;
    rep(i, N) {
        rep(j, min(i, K) + 1) {
            f(i, j);
        }
    }
    rep(i, N + 1) {
        max_D = max(max_D, dp[i][K][0]);
    }

    cout << max_D << endl;
}