#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int H, W;
vector<vector<int>> A(10, vector<int>(10));
int cnt = 0;

set<int> path;

void dfs(int x, int y) {
    int mass = A[x][y];
    if (path.count(mass)) return;

    if (x == H - 1 && y == W - 1) {
        cnt++;
        return;
    }

    path.insert(mass);
    if (x + 1 < H) dfs(x + 1, y);
    if (y + 1 < W) dfs(x, y + 1);
    path.erase(mass);
}

signed main() {
    cin >> H >> W;
    rep(i, H) rep(j, W) cin >> A[i][j];

    dfs(0, 0);

    cout << cnt << endl;
}