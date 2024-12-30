#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, C;
    cin >> N >> C;
    vector<vector<int>> D(C, vector<int>(C));
    rep(i, C) rep(j, C) cin >> D[i][j];
    vector<vector<int>> c(N, vector<int>(N));
    rep(i, N) rep(j, N) cin >> c[i][j];

    rep(i, N) rep(j, N) c[i][j]--;

    map<pair<int, int>, int> cnt;
    rep(i, N) {
        rep(j, N) {
            cnt[make_pair((i + j) % 3, c[i][j])]++;
            debug(cnt[make_pair((i + j) % 3, c[i][j])]);
        }
    }

    int ans = 1e18;
    rep(c1, C) {
        rep(c2, C) {
            rep(c3, C) {
                if (c1 == c2 || c1 == c3 || c2 == c3) continue;

                int cost = 0;
                rep(c, C) cost += cnt[{0, c}] * D[c][c1];
                rep(c, C) cost += cnt[{1, c}] * D[c][c2];
                rep(c, C) cost += cnt[{2, c}] * D[c][c3];

                ans = min(ans, cost);
                // cout << cost << " " << c1 << " " << c2 << " " << c3 << endl;
            }
        }
    }

    cout << ans << endl;
}
