#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> G(H);
    rep(i, H) {
        cin >> G[i];
    }
    int loop_cnt = 0;
    int x = 0, y = 0;
    while (1) {
        if (loop_cnt > H * W + 10) {
            cout << -1 << endl;
            return 0;
        }
        if (G[x][y] == 'U' && x != 0) {
            x--;
        } else if (G[x][y] == 'D' && x != H - 1) {
            x++;
        } else if (G[x][y] == 'L' && y != 0) {
            y--;
        } else if (G[x][y] == 'R' && y != W - 1) {
            y++;
        } else {
            break;
        }
        loop_cnt++;
    }
    cout << x + 1 << " " << y + 1 << endl;
}