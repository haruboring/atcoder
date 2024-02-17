#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int H, W, N;
    cin >> H >> W >> N;
    string T;
    cin >> T;
    vector<string> S(H);
    rep(i, H) cin >> S[i];

    int ans = 0;

    rep(i, H) {
        rep(j, W) {
            int pi = i, pj = j;
            bool ok = true;
            if (S[pi][pj] == '#') ok = false;
            rep(k, N) {
                if (T[k] == 'L') pj--;
                if (T[k] == 'R') pj++;
                if (T[k] == 'U') pi--;
                if (T[k] == 'D') pi++;
                if (pi < 0 || pi >= H || pj < 0 || pj >= W) {
                    ok = false;
                    break;
                }
                if (S[pi][pj] == '#') {
                    ok = false;
                    break;
                }
            }

            if (ok) ans++;
        }
    }

    cout << ans << endl;
}
