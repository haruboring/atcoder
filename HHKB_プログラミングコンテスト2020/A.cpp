// #include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int fast_pow(int a, int b, int MOD) {
    int ans = 1;
    while (b > 0) {
        if (b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

signed main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H) cin >> S[i];

    int MOD = 1e9 + 7;

    vector<vector<int>> direct_i(H, vector<int>(W, 0)), direct_j(H, vector<int>(W, 0));
    rep(j, W) {
        int sum = 0;
        rep(i, H) {
            if (S[i][j] == '#' || i == H - 1) {
                if (S[i][j] != '#') sum++;
                for (int k = i; k >= 0; k--) {
                    if (S[k][j] == '#' && k != i) break;
                    direct_i[k][j] = sum;
                }
                sum = 0;
            } else {
                sum++;
            }
        }
    }
    rep(i, H) {
        int sum = 0;
        rep(j, W) {
            if (S[i][j] == '#' || j == W - 1) {
                if (S[i][j] != '#') sum++;
                for (int k = j; k >= 0; k--) {
                    if (S[i][k] == '#' && k != j) break;
                    direct_j[i][k] = sum;
                }
                sum = 0;
            } else {
                sum++;
            }
        }
    }

    int all_sum = 0;
    rep(i, H) {
        rep(j, W) {
            if (S[i][j] == '.') all_sum++;
        }
    }

    int ans = 0;
    rep(i, H) {
        rep(j, W) {
            if (S[i][j] == '#') continue;
            int lamps = direct_i[i][j] + direct_j[i][j] - 1;
            if (lamps == 0) continue;
            int tmp = fast_pow(2, lamps, MOD);
            tmp += MOD - 1;
            tmp %= MOD;

            tmp *= fast_pow(2, all_sum - lamps, MOD);
            tmp %= MOD;
            ans += tmp;
            ans %= MOD;
        }
    }

    cout << ans << endl;
}