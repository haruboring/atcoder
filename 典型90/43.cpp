#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int H, W;
    cin >> H >> W;
    int rs, cs;
    cin >> rs >> cs;
    int rt, ct;
    cin >> rt >> ct;
    rs--, cs--, rt--, ct--;
    vector<string> S(H);
    rep(i, H) cin >> S[i];

    vector<pair<int, int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    queue<pair<int, int>> q;
    vector<vector<int>> dist(H, vector<int>(W, 1e9));
    q.push({rs, cs});
    dist[rs][cs] = 0;
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        int cost = dist[r][c];
        for (auto [dr, dc] : d) {
            int nr = r, nc = c;
            while (true) {
                nr += dr;
                nc += dc;
                if (nr < 0 || nr >= H || nc < 0 || nc >= W) break;
                if (S[nr][nc] == '#') break;
                if (dist[nr][nc] < cost + 1) break;
                dist[nr][nc] = cost + 1;
                q.push({nr, nc});

                if (nr == rt && nc == ct) {
                    cout << dist[nr][nc] - 1 << endl;
                    return 0;
                }
            }
        }
    }

    // cout << endl;
    // rep(i, H) {
    //     rep(j, W) {
    //         if (dist[i][j] == 1e9)
    //             cout << 'x' << "";
    //         else
    //             cout << dist[i][j] << "";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    cout << -1 << endl;
}