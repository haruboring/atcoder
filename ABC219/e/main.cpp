#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

vector<int> par(16);

void init(int n) {
    rep(i, n) par[i] = i;
}

int root(int x) {
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
}

int unite(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if (ry < rx) swap(rx, ry);
    if (rx == ry) {
        return 0;
    } else {
        return par[rx] = ry;
    }
}

signed main() {
    vector<vector<int>> A(4, vector<int>(4));
    rep(i, 4) rep(j, 4) cin >> A[i][j];

    set<pair<int, int>> s;
    rep(i, 4) rep(j, 4) if (A[i][j] == 1) s.insert({i, j});

    int ans = 0;
    repp(i, 1, 1 << 16) {
        vector<vector<int>> B(4, vector<int>(4));
        init(16);
        rep(j, 16) if (i >> j & 1) {
            B[j / 4][j % 4] = 1;
        }
        rep(j, 4) rep(k, 4) if (B[j][k] == 1) {
            if (j > 0 && B[j - 1][k] == 1) unite(j * 4 + k, (j - 1) * 4 + k);
            if (j < 3 && B[j + 1][k] == 1) unite(j * 4 + k, (j + 1) * 4 + k);
            if (k > 0 && B[j][k - 1] == 1) unite(j * 4 + k, j * 4 + k - 1);
            if (k < 3 && B[j][k + 1] == 1) unite(j * 4 + k, j * 4 + k + 1);
        }

        set<int> st;
        rep(j, 16) if (B[j / 4][j % 4] == 1) st.insert(root(j));
        if (st.size() != 1) continue;
        bool ok = true;
        for (auto [x, y] : s)
            if (B[x][y] != 1) ok = false;
        if (!ok) continue;

        vector<vector<bool>> C(4, vector<bool>(4, false));
        rep(j, 4) {
            queue<pair<int, int>> q;
            if (B[j][0] == 0) q.push({j, 0});
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                if (x < 0 || x >= 4 || y < 0 || y >= 4) continue;
                if (C[x][y]) continue;
                C[x][y] = true;
                if (x > 0 && B[x - 1][y] == 0 && !C[x - 1][y]) q.push({x - 1, y});
                if (x < 3 && B[x + 1][y] == 0 && !C[x + 1][y]) q.push({x + 1, y});
                if (y > 0 && B[x][y - 1] == 0 && !C[x][y - 1]) q.push({x, y - 1});
                if (y < 3 && B[x][y + 1] == 0 && !C[x][y + 1]) q.push({x, y + 1});
            }
        }
        rep(j, 4) {
            queue<pair<int, int>> q;
            if (B[j][3] == 0) q.push({j, 3});
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                if (x < 0 || x >= 4 || y < 0 || y >= 4) continue;
                if (C[x][y]) continue;
                C[x][y] = true;
                if (x > 0 && B[x - 1][y] == 0 && !C[x - 1][y]) q.push({x - 1, y});
                if (x < 3 && B[x + 1][y] == 0 && !C[x + 1][y]) q.push({x + 1, y});
                if (y > 0 && B[x][y - 1] == 0 && !C[x][y - 1]) q.push({x, y - 1});
                if (y < 3 && B[x][y + 1] == 0 && !C[x][y + 1]) q.push({x, y + 1});
            }
        }
        rep(j, 4) {
            queue<pair<int, int>> q;
            if (B[0][j] == 0) q.push({0, j});
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                if (x < 0 || x >= 4 || y < 0 || y >= 4) continue;
                if (C[x][y]) continue;
                C[x][y] = true;
                if (x > 0 && B[x - 1][y] == 0 && !C[x - 1][y]) q.push({x - 1, y});
                if (x < 3 && B[x + 1][y] == 0 && !C[x + 1][y]) q.push({x + 1, y});
                if (y > 0 && B[x][y - 1] == 0 && !C[x][y - 1]) q.push({x, y - 1});
                if (y < 3 && B[x][y + 1] == 0 && !C[x][y + 1]) q.push({x, y + 1});
            }
        }
        rep(j, 4) {
            queue<pair<int, int>> q;
            if (B[3][j] == 0) q.push({3, j});
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                if (x < 0 || x >= 4 || y < 0 || y >= 4) continue;
                if (C[x][y]) continue;
                C[x][y] = true;
                if (x > 0 && B[x - 1][y] == 0 && !C[x - 1][y]) q.push({x - 1, y});
                if (x < 3 && B[x + 1][y] == 0 && !C[x + 1][y]) q.push({x + 1, y});
                if (y > 0 && B[x][y - 1] == 0 && !C[x][y - 1]) q.push({x, y - 1});
                if (y < 3 && B[x][y + 1] == 0 && !C[x][y + 1]) q.push({x, y + 1});
            }
        }

        rep(j, 4) rep(k, 4) if (B[j][k] == 0 && C[j][k] == false) ok = false;

        if (!ok) continue;
        ans++;
    }

    cout << ans << endl;
}