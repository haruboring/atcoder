#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

bool is_already_include_this_cupon(int sum, int this_index) {
    bool ans = false;
    for (int i = 15; i >= 0; i--) {
        if (pow(2, i) <= sum) {
            sum -= pow(2, i);
            if (i == this_index) {
                ans = true;
            }
        }
    }
    return ans;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(M + 1, vector<int>(N + 1));
    rep(i, M) {
        rep(j, N) {
            cin >> A[i + 1][j + 1];
        }
    }
    vector<vector<int>> dp(M + 1, vector<int>(1 << N));
    int no = N + 100;
    rep(i, M + 1) {
        rep(j, 1 << N) {
            dp[i][j] = no;
        }
    }
    dp[0][0] = 0;
    rep(i, M) {
        rep(j, 1 << N) {
            if (dp[i][j] != no) {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
                int sum = 0;
                rep(k, N) {
                    if (A[i + 1][k + 1] == 1) {
                        if (is_already_include_this_cupon(j, k) == false) {
                            sum += pow(2, k);
                            dp[i + 1][j + sum] = min(dp[i + 1][j + sum], dp[i][j] + 1);
                        }
                    }
                }
            }
        }
    }

    if (dp[M][(1 << N) - 1] == no) {
        dp[M][(1 << N) - 1] = -1;
    }
    cout << dp[M][(1 << N) - 1] << endl;
}