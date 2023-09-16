#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    ll N;
    cin >> N;
    vector<vector<ll>> X(N + 1, vector<ll>(0)), min_max_X(N + 1, vector<ll>(2));
    set<int> colors;
    rep(i, N) {
        ll x, c;
        cin >> x >> c;
        X[c].push_back(x);
        colors.insert(c);
    }
    vector<vector<ll>> dp(N + 1, vector<ll>(2, (1LL << 60)));
    for (int color : colors) {
        sort(all(X[color]));
        min_max_X[color][0] = X[color][0];
        // TODO: X[color][-1] はあかんの？？？？Pythonはいけるよね多分？後で確認
        // →*rbegin(X[color])でよかったわ普通に
        min_max_X[color][1] = X[color][X[color].size() - 1];
    }

    dp[0][0] = 0;
    dp[0][1] = 0;
    int ex_color = 0;
    for (int color : colors) {
        dp[color][0] = min(dp[color][0], dp[ex_color][0] + abs(min_max_X[color][1] - min_max_X[ex_color][0]) + (min_max_X[color][1] - min_max_X[color][0]));
        dp[color][0] = min(dp[color][0], dp[ex_color][1] + abs(min_max_X[color][1] - min_max_X[ex_color][1]) + (min_max_X[color][1] - min_max_X[color][0]));
        dp[color][1] = min(dp[color][1], dp[ex_color][0] + abs(min_max_X[color][0] - min_max_X[ex_color][0]) + (min_max_X[color][1] - min_max_X[color][0]));
        dp[color][1] = min(dp[color][1], dp[ex_color][1] + abs(min_max_X[color][0] - min_max_X[ex_color][1]) + (min_max_X[color][1] - min_max_X[color][0]));
        ex_color = color;
    }
    cout << min(dp[ex_color][0] + abs(min_max_X[ex_color][0] - 0), dp[ex_color][1] + abs(min_max_X[ex_color][1] - 0)) << endl;
}