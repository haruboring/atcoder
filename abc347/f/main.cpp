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
    vector<string> A(H);
    rep(i, H) cin >> A[i];
    int N;
    cin >> N;
    vector<int> R(N), C(N), E(N);
    rep(i, N) cin >> R[i] >> C[i] >> E[i];

    rep(i, N) R[i]--, C[i]--;

    map<pair<int, int>, int> med;
    rep(i, N) {
        med[{R[i], C[i]}] = E[i];
    }

    pair<int, int> s, t;
    rep(i, H) rep(j, W) {
        if (A[i][j] == 'S') s = {i, j};
        if (A[i][j] == 'T') t = {i, j};
    }

    set<pair<int, int>> md;
    for (auto [p, e] : med) {
        md.insert(p);
    }

    debug(s.first);

    vector<pair<int, int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> dp(H, vector<int>(W, -1e9));
    dp[s.first][s.second] = 0;
    priority_queue<tuple<int, int, int>> q;
    q.push({0, s.first, s.second});
    while (!q.empty()) {
        auto [d, i, j] = q.top();
        q.pop();
        if (i == t.first && j == t.second) {
            cout << "Yes" << endl;
            return 0;
        }
        if (md.count({i, j}) && d < med[{i, j}]) {
            d = med[{i, j}];
            med[{i, j}] = 0;
            md.erase({i, j});
        }

        for (auto [di, dj] : moves) {
            int ni = i + di, nj = j + dj;
            if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
            if (A[ni][nj] == '#') continue;
            if (d - 1 < 0) continue;
            if (dp[ni][nj] >= d - 1) continue;
            dp[ni][nj] = d - 1;
            q.push({d - 1, ni, nj});
        }
    }

    cout << "No" << endl;
}
