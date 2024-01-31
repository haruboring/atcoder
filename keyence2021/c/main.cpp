#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int MOD = 998244353;

int llpow(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

// a^n mod を計算する
int modpow(int a, int n) {
    int res = 1;
    while (n > 0) {
        debug(n);
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

// a^{-1} mod を計算する
int modinv(int a) {
    return modpow(a, MOD - 2);
}

signed main() {
    int H, W, K;
    cin >> H >> W >> K;
    vector<int> h(K), w(K);
    vector<char> c(K);
    rep(i, K) {
        cin >> h[i] >> w[i] >> c[i];
        h[i]--;
        w[i]--;
    }

    set<pair<int, int>> s;
    rep(i, K) s.insert(make_pair(h[i], w[i]));

    map<char, vector<pair<int, int>>> move;
    move['R'].push_back(make_pair(0, 1));
    move['D'].push_back(make_pair(1, 0));
    move['X'].push_back(make_pair(0, 1));
    move['X'].push_back(make_pair(1, 0));
    move['Z'].push_back(make_pair(0, 1));
    move['Z'].push_back(make_pair(1, 0));
    move['Z'].push_back(make_pair(0, 1));
    move['Z'].push_back(make_pair(1, 0));
    map<pair<int, int>, char> mp;
    rep(i, K) mp[{h[i], w[i]}] = c[i];

    vector<vector<int>> a = {{0, 1}, {1, 0}, {0, 1}, {1, 0}};

    vector<vector<int>> dp(H, vector<int>(W, 0));
    dp[0][0] = 1;
    rep(i, H * W - K) {
        dp[0][0] *= 3;
        dp[0][0] %= MOD;
    }

    debug(dp[0][0]);

    int modinv_3 = modinv(3);

    rep(i, H) {
        rep(j, W) {
            if (s.count({i, j})) {
                char c = mp[{i, j}];
                for (auto [dx, dy] : move[c]) {
                    int nx = i + dx;
                    int ny = j + dy;
                    if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                    dp[nx][ny] += dp[i][j];
                    dp[nx][ny] %= MOD;
                }
            } else {
                rep(k, 4) {
                    int nx = i + a[k][0];
                    int ny = j + a[k][1];
                    if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                    dp[nx][ny] += dp[i][j] * modinv_3 % MOD;
                    dp[nx][ny] %= MOD;
                }
            }
        }
    }

    cout << dp[H - 1][W - 1] << endl;
}
