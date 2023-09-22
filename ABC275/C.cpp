#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    vector<string> S(9);
    rep(i, 9) cin >> S[i];

    int ans = 0;
    for (int l = -8; l < 9; l++) {
        for (int r = -8; r < 9; r++) {
            if (l == 0 && r == 0) continue;
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (i + l < 0 || i + l >= 9) continue;
                    if (j + r < 0 || j + r >= 9) continue;
                    if (i + r < 0 || i + r >= 9) continue;
                    if (j - l < 0 || j - l >= 9) continue;
                    if (i + l + r < 0 || i + l + r >= 9) continue;
                    if (j + r - l < 0 || j + r - l >= 9) continue;
                    if (S[i][j] == '.') continue;
                    if (S[i + l][j + r] == '.') continue;
                    if (S[i + r][j - l] == '.') continue;
                    if (S[i + l + r][j + r - l] == '.') continue;
                    ans++;
                }
            }
        }
    }

    cout << ans / 4 << endl;
}
