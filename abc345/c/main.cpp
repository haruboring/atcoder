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

    int N = S.size();

    int ans = 0;
    bool dup = false;

    for (char c = 'a'; c <= 'z'; c++) {
        vector<int> cnt(N, 0);
        rep(i, N) {
            if (i != 0) cnt[i] = cnt[i - 1];
            if (S[i] == c) {
                cnt[i]++;
            }
        }
        if (cnt[N - 1] > 1) dup = true;
        repp(i, 1, N) {
            if (S[i] != c) {
                ans += cnt[i];
            }
        }
    }
    if (dup) ans++;
    cout << ans << endl;
}
