#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int H, W;
vector<string> S(2000 + 100);
vector<vector<int>> ans(2000 + 100, vector<int>(2000 + 100, 1e18));
vector<vector<bool>> visited(2000 + 100, vector<bool>(2000 + 100, false));

int dp(int x, int y) {
    if (x == H - 1 && y == W - 1) {
        ans[x][y] = 0;
        return ans[x][y];
    }
    if (visited[x][y]) return ans[x][y];

    int turn = (x + y) % 2;

    if (turn == 0) {
        ans[x][y] = -1e18;
        if (x + 1 < H) ans[x][y] = max(ans[x][y], dp(x + 1, y) + (S[x + 1][y] == '+' ? 1 : -1));
        if (y + 1 < W) ans[x][y] = max(ans[x][y], dp(x, y + 1) + (S[x][y + 1] == '+' ? 1 : -1));
    } else {
        ans[x][y] = 1e18;
        if (x + 1 < H) ans[x][y] = min(ans[x][y], dp(x + 1, y) + (S[x + 1][y] == '+' ? -1 : 1));
        if (y + 1 < W) ans[x][y] = min(ans[x][y], dp(x, y + 1) + (S[x][y + 1] == '+' ? -1 : 1));
    }

    visited[x][y] = true;
    return ans[x][y];
}
signed main() {
    cin >> H >> W;
    rep(i, H) cin >> S[i];

    dp(0, 0);

    if (ans[0][0] > 0) {
        cout << "Takahashi" << endl;
    } else if (ans[0][0] < 0) {
        cout << "Aoki" << endl;
    } else {
        cout << "Draw" << endl;
    }
}