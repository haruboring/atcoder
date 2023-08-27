#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

vector<int> par(4000000 + 100);

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
    if (rx == ry) {
        return 0;
    } else {
        return par[rx] = ry;
    }
}

int main() {
    int H, W;
    cin >> H >> W;
    int Q;
    cin >> Q;

    init(H * W);
    vector<pair<int, int>> move = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    vector<vector<bool>> is_red(H, vector<bool>(W, false));
    rep(i, Q) {
        int flag;
        cin >> flag;
        if (flag == 1) {
            int r, c;
            cin >> r >> c;
            r--;
            c--;
            is_red[r][c] = true;
            int x = r * W + c;
            for (auto [dr, dc] : move) {
                int nr = r + dr;
                int nc = c + dc;
                if (nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
                if (!is_red[nr][nc]) continue;
                int y = nr * W + nc;
                unite(x, y);
            }
        } else {
            int ra, ca, rb, cb;
            cin >> ra >> ca >> rb >> cb;
            ra--;
            ca--;
            rb--;
            cb--;
            int x = ra * W + ca;
            int y = rb * W + cb;
            if (is_red[ra][ca] && root(x) == root(y))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
}