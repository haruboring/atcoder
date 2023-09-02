#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    ll mod = 200;

    vector<vector<vector<string>>> dp(N + 1, vector<vector<string>>(mod, vector<string>(0)));
    dp[0][0].push_back("");
    rep(i, N) {
        rep(j, mod) {
            for (auto s : dp[i][j]) {
                // 選択しない
                dp[i + 1][j].push_back(s);
                // 選択する
                dp[i + 1][(j + A[i]) % mod].push_back(s + to_string(i + 1) + " ");
            }
        }

        // 200で割った余りが0になるものがあれば終了
        rep(j, mod) {
            if (j == 0) {
                if (dp[i + 1][j].size() >= 3) {
                    cout << "Yes" << endl;
                    string S1 = dp[i + 1][j][1];
                    string S2 = dp[i + 1][j][2];
                    cout << S1.size() / 2 << " " << S1 << endl;
                    cout << S2.size() / 2 << " " << S2 << endl;
                    return 0;
                }
            } else {
                if (dp[i + 1][j].size() >= 2) {
                    cout << "Yes" << endl;
                    string S1 = dp[i + 1][j][0];
                    string S2 = dp[i + 1][j][1];
                    cout << S1.size() / 2 << " " << S1 << endl;
                    cout << S2.size() / 2 << " " << S2 << endl;
                    return 0;
                }
            }
        }
    }

    cout << "No" << endl;
}
