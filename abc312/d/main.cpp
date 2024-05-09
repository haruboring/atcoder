#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

ll mod = 998244353;
vector<vector<vector<ll>>> dp(3000 + 100, vector<vector<ll>>(3000 + 100, vector<ll>(2)));

int main() {
    string S;
    cin >> S;
    int n = S.size();
    S = '?' + S;
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k < 2; k++) {
                if (S[i + 1] == '(' || S[i + 1] == '?') {
                    dp[i + 1][j + 1][k] += dp[i][j][k];
                    dp[i + 1][j + 1][k] %= mod;
                }
                if (j && (S[i + 1] == ')' || S[i + 1] == '?')) {
                    dp[i + 1][j - 1][k | (i - j + 1 >= j)] += dp[i][j][k];
                    dp[i + 1][j - 1][k | (i - j + 1 >= j)] %= mod;
                }
            }
        }
    }
    cout << (dp[n][0][0] + dp[n][0][1]) % mod << endl;
    return 0;
}