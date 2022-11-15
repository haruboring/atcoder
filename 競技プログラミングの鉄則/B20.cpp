#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    string S, T;
    cin >> S >> T;
    int s_size = S.size(), t_size = T.size();
    vector<vector<int>> dp(s_size + 1, vector<int>(t_size + 1));
    rep(i, s_size + 1) {
        dp[i][0] = i;
    }
    rep(i, t_size + 1) {
        dp[0][i] = i;
    }
    repp(i, 1, s_size + 1) {
        repp(j, 1, t_size + 1) {
            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
            if (S[i - 1] == T[j - 1]) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            } else {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }
    cout << dp[s_size][t_size] << endl;
}