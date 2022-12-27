#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int H, W;
vector<string> S(0);
vector<vector<int>> dp(55, vector<int>(55, 10000));

void bfs(int i, int j, int dis) {
    dp[i][j] = min(dp[i][j], dis);
    if (0 <= i && i < H && 0 <= j + 1 && j + 1 < W && S[i][j + 1] == '.' && dis + 1 < dp[i][j + 1]) {
        bfs(i, j + 1, dis + 1);
    }
    if (0 <= i && i < H && 0 <= j - 1 && j - 1 < W && S[i][j - 1] == '.' && dis + 1 < dp[i][j - 1]) {
        bfs(i, j - 1, dis + 1);
    }
    if (0 <= i + 1 && i + 1 < H && 0 <= j && j < W && S[i + 1][j] == '.' && dis + 1 < dp[i + 1][j]) {
        bfs(i + 1, j, dis + 1);
    }
    if (0 <= i - 1 && i - 1 < H && 0 <= j && j < W && S[i - 1][j] == '.' && dis + 1 < dp[i - 1][j]) {
        bfs(i - 1, j, dis + 1);
    }
}
int main() {
    cin >> H >> W;
    int cnt = 0;
    rep(i, H) {
        string s;
        cin >> s;
        S.push_back(s);
        rep(j, s.size()){
            if(s[j]=='.'){
                cnt++;
            }
        }
    }
    bfs(0, 0, 1);
    if (dp[H - 1][W - 1] == 10000) {
        cout << -1 << endl;
    } else {
        cout << cnt - dp[H - 1][W - 1] << endl;
    }
}