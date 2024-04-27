#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

vector<int> par(200'0000 + 100);

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
    int H, W;
    cin >> H >> W;
    vector<string> S(H), Ss;
    rep(i, H) cin >> S[i];

    Ss = S;

    rep(i, H) {
        rep(j, W) {
            if (S[i][j] == '#') {
                if (i > 0) Ss[i - 1][j] = '#';
                if (i < H - 1) Ss[i + 1][j] = '#';
                if (j > 0) Ss[i][j - 1] = '#';
                if (j < W - 1) Ss[i][j + 1] = '#';
            }
        }
    }

    init(H * W + 100);
    rep(i, H) {
        rep(j, W) {
            if (Ss[i][j] == '#') continue;
            if (i > 0 && Ss[i - 1][j] == '.') unite(i * W + j, (i - 1) * W + j);
            if (i < H - 1 && Ss[i + 1][j] == '.') unite(i * W + j, (i + 1) * W + j);
            if (j > 0 && Ss[i][j - 1] == '.') unite(i * W + j, i * W + j - 1);
            if (j < W - 1 && Ss[i][j + 1] == '.') unite(i * W + j, i * W + j + 1);
        }
    }

    map<int, int> mp;
    rep(i, H * W) {
        if (S[i / W][i % W] == '#') continue;
        mp[root(i)]++;
    }

    rep(i, H) {
        rep(j, W) {
            if (S[i][j] == '.' && Ss[i][j] == '#') {
                set<int> a;
                if (i > 0 && Ss[i - 1][j] == '.') a.insert(root((i - 1) * W + j));
                if (i < H - 1 && Ss[i + 1][j] == '.') a.insert(root((i + 1) * W + j));
                if (j > 0 && Ss[i][j - 1] == '.') a.insert(root(i * W + j - 1));
                if (j < W - 1 && Ss[i][j + 1] == '.') a.insert(root(i * W + j + 1));

                for (auto x : a) {
                    mp[x]++;
                }
            }
        }
    }

    int ans = 0;
    for (auto [a, cnt] : mp) {
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}
