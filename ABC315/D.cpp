#include "atcoder/all"
#include "bits/stdc++.h"
// #define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

// 小文字だけ→26個しかねえぞ！！

signed main() {
    int H, W;
    cin >> H >> W;
    vector<string> c(H);
    rep(i, H) cin >> c[i];

    vector<vector<int>> cnt_i(H, vector<int>(26)), cnt_j(W, vector<int>(26));

    rep(i, H) rep(j, W) cnt_i[i][c[i][j] - 'a']++;
    rep(j, W) rep(i, H) cnt_j[j][c[i][j] - 'a']++;

    set<int> deleted_i, deleted_j;
    int hc = H, wc = W;

    rep(_, H + W) {
        vector<int> del_i(0), del_j(0);

        rep(i, H) {
            if (deleted_i.count(i)) continue;
            for (int c = 0; c < 26; c++) {
                if (cnt_i[i][c] == wc && wc > 1) {
                    del_i.push_back(i);
                }
            }
        }

        rep(j, W) {
            if (deleted_j.count(j)) continue;
            for (int c = 0; c < 26; c++) {
                if (cnt_j[j][c] == hc && hc > 1) {
                    del_j.push_back(j);
                }
            }
        }

        rep(ii, del_i.size()) {
            int i = del_i[ii];
            deleted_i.insert(i);
            rep(j, W) {
                cnt_j[j][c[i][j] - 'a']--;
            }
            hc--;
        }

        rep(jj, del_j.size()) {
            int j = del_j[jj];
            deleted_j.insert(j);
            rep(i, H) {
                cnt_i[i][c[i][j] - 'a']--;
            }
            wc--;
        }
    }

    cout << hc * wc << endl;
}