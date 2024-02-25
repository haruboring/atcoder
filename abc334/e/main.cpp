#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using mint = atcoder::modint998244353;

vector<int> par(2000'000 + 100);

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
    vector<string> S(H);
    rep(i, H) cin >> S[i];

    init(H * W);
    rep(i, H) {
        rep(j, W) {
            if (S[i][j] == '.') continue;
            if (i - 1 >= 0 && S[i - 1][j] == '#') unite(i * W + j, (i - 1) * W + j);
            if (i + 1 < H && S[i + 1][j] == '#') unite(i * W + j, (i + 1) * W + j);
            if (j - 1 >= 0 && S[i][j - 1] == '#') unite(i * W + j, i * W + j - 1);
            if (j + 1 < W && S[i][j + 1] == '#') unite(i * W + j, i * W + j + 1);
        }
    }
    set<int> roots;
    rep(i, H) {
        rep(j, W) {
            if (S[i][j] == '#') {
                roots.insert(root(i * W + j));
            }
        }
    }
    int size = roots.size();
    debug(size);

    int random_size = 0;
    rep(i, H) {
        rep(j, W) {
            if (S[i][j] == '.') random_size++;
        }
    }

    mint ans = 0;
    rep(i, H) {
        rep(j, W) {
            if (S[i][j] == '#') continue;
            set<int> connect;
            if (i - 1 >= 0 && S[i - 1][j] == '#') connect.insert(root((i - 1) * W + j));
            if (i + 1 < H && S[i + 1][j] == '#') connect.insert(root((i + 1) * W + j));
            if (j - 1 >= 0 && S[i][j - 1] == '#') connect.insert(root(i * W + j - 1));
            if (j + 1 < W && S[i][j + 1] == '#') connect.insert(root(i * W + j + 1));

            int connect_size = connect.size();

            ans += mint(size + 1 - connect_size) / mint(random_size);
        }
    }

    cout << ans.val() << endl;
}
