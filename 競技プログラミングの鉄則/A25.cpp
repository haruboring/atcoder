#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int H, W;
vector<string> c(0);
vector<vector<ll>> cnt(35, vector<ll>(35, 0));

int main() {
    cin >> H >> W;
    rep(i, H) {
        string s;
        cin >> s;
        c.push_back(s);
    }
    cnt[1][1] = 1;
    repp(i, 1, H + 1) {
        repp(j, 1, W + 1) {
            if (i == 1 && j == 1) {
                continue;
            }
            if (c[i - 1][j - 1] == '.') {
                cnt[i][j] = cnt[i - 1][j] + cnt[i][j - 1];
            }
        }
    }

    cout << cnt[H][W] << endl;
}