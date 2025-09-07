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
    vector<string> S(H);
    rep(i, H) cin >> S[i];

    bool f = true;
    rep(i, H) {
        rep(j, W) {
            if (S[i][j] == '.') continue;
            int cnt = 0;
            if (i + 1 < H && S[i + 1][j] == '#') cnt++;
            if (i - 1 >= 0 && S[i - 1][j] == '#') cnt++;
            if (j + 1 < W && S[i][j + 1] == '#') cnt++;
            if (j - 1 >= 0 && S[i][j - 1] == '#') cnt++;
            if (cnt != 2 && cnt != 4) f = false;
        }
    }

    if (f) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
