#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int R, C, K;
    cin >> R >> C >> K;
    vector<string> S(R);
    rep(i, R) cin >> S[i];

    int cnt = 0;
    repp(i, K - 1, R - K + 2) {
        repp(j, K - 1, C - K + 2) {
            bool ok = true;
            rep(k, K) {
                rep(l, k + 1) {
                    int m = k - l;
                    if (!(i + l < R && j - m >= 0 && i - l >= 0 && j + m < C)) {
                        ok = false;
                        continue;
                    }
                    if (S[i + l][j - m] == 'x') ok = false;
                    if (S[i + l][j + m] == 'x') ok = false;
                    if (S[i - l][j - m] == 'x') ok = false;
                    if (S[i - l][j + m] == 'x') ok = false;
                }
            }
            if (ok) cnt++;
        }
    }

    cout << cnt << endl;
}
