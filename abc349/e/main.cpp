#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

vector<vector<int>> A(3, vector<int>(3)), used(3, vector<int>(3, 0));

bool dfs(int t) {
    if (t == 9) {
        // Aokiの手番
        int sum = 0;
        rep(i, 3) {
            rep(j, 3) {
                if (used[i][j] == -1) {
                    sum += A[i][j];
                } else {
                    sum -= A[i][j];
                }
            }
        }
        if (sum > 0) {
            return true;
        } else {
            return false;
        }
    }

    // 置く前に勝敗判定
    // 横
    rep(i, 3) {
        if (used[i][0] == used[i][1] && used[i][1] == used[i][2] && used[i][0] != 0) {
            return false;
        }
    }
    // 縦
    rep(i, 3) {
        if (used[0][i] == used[1][i] && used[1][i] == used[2][i] && used[0][i] != 0) {
            return false;
        }
    }
    // 斜め
    if (used[0][0] == used[1][1] && used[1][1] == used[2][2] && used[0][0] != 0) {
        return false;
    }
    if (used[0][2] == used[1][1] && used[1][1] == used[2][0] && used[0][2] != 0) {
        return false;
    }

    int cnt = 0;
    rep(i, 3) {
        rep(j, 3) {
            if (used[i][j] == 0) {
                if (t % 2 == 0) {
                    used[i][j] = 1;
                } else {
                    used[i][j] = -1;
                }
                if (!dfs(t + 1)) {
                    cnt++;
                }
                used[i][j] = 0;
            }
        }
    }
    if (cnt == 0) {
        return false;
    } else {
        return true;
    }
}

signed main() {
    rep(i, 3) rep(j, 3) cin >> A[i][j];

    if (dfs(0)) {
        cout << "Takahashi" << endl;
    } else {
        cout << "Aoki" << endl;
    }
}
