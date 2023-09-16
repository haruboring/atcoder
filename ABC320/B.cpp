#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    string S;
    cin >> S;

    int ans = 0;
    rep(i, S.size()) {
        repp(j, i, S.size()) {
            bool ok = true;
            rep(k, (j - i + 1) / 2) {
                if (S[i + k] != S[j - k]) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                ans = max(ans, j - i + 1);
            }
        }
    }

    cout << ans << endl;
}