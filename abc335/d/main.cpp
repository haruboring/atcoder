#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N;
    cin >> N;

    vector<vector<int>> ans(N, vector<int>(N, 0));
    ans[N / 2][N / 2] = -1;  // T

    int x = 0, y = 0;
    int order = 1;
    while (ans[x][y] != -1) {
        while (0 <= x && x < N && 0 <= y && y < N && ans[x][y] == 0) {
            ans[x][y] = order;
            order++;
            y++;
        }
        y--;
        x++;
        while (0 <= x && x < N && 0 <= y && y < N && ans[x][y] == 0) {
            ans[x][y] = order;
            order++;
            x++;
        }
        x--;
        y--;
        while (0 <= x && x < N && 0 <= y && y < N && ans[x][y] == 0) {
            ans[x][y] = order;
            order++;
            y--;
        }
        y++;
        x--;
        while (0 <= x && x < N && 0 <= y && y < N && ans[x][y] == 0) {
            ans[x][y] = order;
            order++;
            x--;
        }
        x++;
        y++;
    }

    rep(i, N) {
        rep(j, N) {
            if (ans[i][j] == -1) {
                cout << "T ";
            } else {
                cout << ans[i][j] << " ";
            }
        }
        cout << endl;
    }
}
