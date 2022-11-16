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
    P[0] = 0, P[N + 1] = 0, A[0] = 0, A[N + 1] = 0;
    rep(i, N) {
        cin >> P[i + 1] >> A[i + 1];
    }
    vector<vector<int>> dp(N + 2, vector<int>(N + 2));
    dp[1][N] = 0;
    for (int len = N - 1; len >= 0; len--) {
        for (int i = 1; i <= N - len; i++) {
            int j = i + len;
            int break_left_point = 0;
            int break_right_point = 0;
            if (i <= P[i - 1] && P[i - 1] <= j) {
                break_left_point = A[i - 1];
            }
            if (i <= P[j + 1] && P[j + 1] <= j) {
                break_right_point = A[j + 1];
            }
            if (i == 1) {
                dp[i][j] = dp[i][j + 1] + break_right_point;
            } else if (j == N) {
                dp[i][j] = dp[i - 1][j] + break_left_point;
            } else {
                dp[i][j] = max(dp[i - 1][j] + break_left_point, dp[i][j + 1] + break_right_point);
            }
        }
    }

    int max_point = 0;
    repp(i, 1, N + 1) {
        max_point = max(max_point, dp[i][i]);
    }
    cout << max_point << endl;
}