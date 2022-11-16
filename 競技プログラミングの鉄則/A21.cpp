#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> P(N + 2), A(N + 2);
    rep(i, N) {
        cin >> P[i + 1] >> A[i + 1];
    }
    vector<vector<int>> dp(N + 2, vector<int>(N + 2));
    dp[1][N] = 0;
    repp(i, 1, N + 1) {
        for (int j = N; j >= i; j--) {
            int break_left_point = 0;
            int break_right_point = 0;
            if (i <= P[i - 1] && P[i - 1] <= j) {
                break_left_point = A[i - 1];
            }
            if (i <= P[j + 1] && P[j + 1] <= j) {
                break_right_point = A[j + 1];
            }
            dp[i][j] = max(dp[i - 1][j] + break_left_point, dp[i][j + 1] + break_right_point);
        }
    }

    int max_point = 0;
    repp(i, 1, N + 1) {
        max_point = max(max_point, dp[i][i]);
    }
    cout << max_point << endl;
}