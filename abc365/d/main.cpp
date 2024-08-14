#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    // Rでぐー0、Pでぱー1、Sでチョキ2
    map<int, pair<int, int>> ok;
    ok[0] = {1, 0};
    ok[1] = {2, 1};
    ok[2] = {0, 2};

    vector<int> Si(N);
    rep(i, N) {
        if (S[i] == 'R') Si[i] = 0;
        if (S[i] == 'P') Si[i] = 1;
        if (S[i] == 'S') Si[i] = 2;
    }

    vector<vector<int>> dp(N + 1, vector<int>(3, -1));
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    rep(i, N) {
        auto [win, draw] = ok[Si[i]];
        rep(j, 3) {
            if (dp[i][j] == -1) continue;
            if (j != win) dp[i + 1][win] = max(dp[i + 1][win], dp[i][j] + 1);
            if (j != draw) dp[i + 1][draw] = max(dp[i + 1][draw], dp[i][j]);
        }
    }

    cout << max({dp[N][0], dp[N][1], dp[N][2]}) << endl;
}
