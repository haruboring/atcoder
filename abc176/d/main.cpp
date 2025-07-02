#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int H, W;
    cin >> H >> W;
    int Ch, Cw, Dh, Dw;
    cin >> Ch >> Cw >> Dh >> Dw;
    vector<string> S(H);
    rep(i, H) cin >> S[i];

    Ch--, Cw--, Dh--, Dw--;

    vector<vector<int>> D(H, vector<int>(W, 1e18));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
    q.push({Ch, Cw, 0});
    while (!q.empty()) {
        auto [i, j, d] = q.top();
        q.pop();

        if (d >= D[i][j]) continue;
        D[i][j] = d;

        for (int di = -2; di < 3; di++) {
            for (int dj = -2; dj < 3; dj++) {
                int ni = i + di, nj = j + dj;
                if (!(0 <= ni && ni < H) || !(0 <= nj && nj < W)) continue;
                if (S[ni][nj] == '#') continue;

                if ((abs(di) == 0 && abs(dj) == 1) || (abs(di) == 1 && abs(dj) == 0)) {
                    if (d < D[ni][nj]) q.push({ni, nj, d});
                } else {
                    if (d + 1 < D[ni][nj]) q.push({ni, nj, d + 1});
                }
            }
        }
    }

    if (D[Dh][Dw] == 1e18) D[Dh][Dw] = -1;
    cout << D[Dh][Dw] << endl;
}
