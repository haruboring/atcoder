#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    string T;
    cin >> T;
    int N;
    cin >> N;
    vector<int> A(N);
    vector<vector<string>> S(N, vector<string>(0));
    rep(i, N) {
        cin >> A[i];
        rep(j, A[i]) {
            string s;
            cin >> s;
            S[i].push_back(s);
        }
    }

    vector<vector<int>> dp(N + 1, vector<int>(T.size() + 1, 1e9));
    dp[0][0] = 0;
    rep(i, N) {
        for (int j = 0; j < T.size(); j++) {
            if (dp[i][j] == 1e9) continue;
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);

            for (string s : S[i]) {
                if (j + s.size() <= T.size() && T.substr(j, s.size()) == s) {
                    dp[i + 1][j + s.size()] = min(dp[i + 1][j + s.size()], dp[i][j] + 1);
                }
            }
        }
    }

    int ans = 1e9;
    rep(i, N) {
        ans = min(ans, dp[i + 1][T.size()]);
    }

    if (ans == 1e9) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}
