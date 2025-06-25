#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int H, W;
vector<vector<int>> S(2000 + 10, vector<int>(2000 + 10)), memo(2000 + 100, vector<int>(2000 + 100, 1e9));

int dfs(int x, int y) {
    if (memo[x][y] != 1e9) return memo[x][y];
    if (x == H - 1 && y == W - 1) return 0;

    if ((x + y) % 2 == 0) {
        int t = -1e9;
        if (x < H - 1) t = max(t, S[x + 1][y] + dfs(x + 1, y));
        if (y < W - 1) t = max(t, S[x][y + 1] + dfs(x, y + 1));
        memo[x][y] = t;
        return t;
    } else {
        int t = 1e9;
        if (x < H - 1) t = min(t, -S[x + 1][y] + dfs(x + 1, y));
        if (y < W - 1) t = min(t, -S[x][y + 1] + dfs(x, y + 1));
        memo[x][y] = t;
        return t;
    }
}

signed main() {
    cin >> H >> W;
    rep(i, H) {
        string s;
        cin >> s;

        rep(j, W) {
            if (s[j] == '+') {
                S[i][j] = 1;
            } else {
                S[i][j] = -1;
            }
        }
    }

    int s = dfs(0, 0);
    debug(s);
    if (s > 0) {
        cout << "Takahashi" << endl;
    } else if (s == 0) {
        cout << "Draw" << endl;
    } else {
        cout << "Aoki" << endl;
    }
}
