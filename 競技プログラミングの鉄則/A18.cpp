#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, S;
    cin >> N >> S;
    vector<int> A(N);
    rep(i, N) {
        cin >> A[i];
    }
    vector<vector<bool>> dp(N + 1, vector<bool>(N * 10000 + 100));
    rep(i, N + 1) {
        rep(j, N * 10000 + 100) {
            dp[i][j] = false;
        }
    }
    dp[0][0] = true;
    repp(i, 1, N + 1) {
        rep(j, N * 10000 + 100) {
            if (dp[i - 1][j]) {
                dp[i][j] = true;
                dp[i][j + A[i - 1]] = true;
            }
        }
    }
    rep(i, N + 1) {
        if (dp[i][S]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}