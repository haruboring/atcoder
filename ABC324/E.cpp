#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N;
    string T;
    cin >> N >> T;
    vector<string> S(N);
    rep(i, N) {
        cin >> S[i];
    }

    vector<int> suff(N);
    rep(i, N) {
        int idx = 0;
        rep(j, S[i].size()) {
            if (S[i][j] == T[idx]) {
                idx++;
            }
        }
        suff[i] = idx;
    }

    vector<int> pref(N);
    rep(i, N) {
        int idx = 0;
        for (int j = S[i].size() - 1; j >= 0; j--) {
            if (S[i][j] == T[T.size() - 1 - idx]) {
                idx++;
            }
        }
        pref[i] = idx;
    }

    vector<int> pref_cnt(N);
    rep(i, N) pref_cnt[i] = pref[i];

    sort(all(pref_cnt));

    int ans = 0;

    rep(i, N) {
        int already = suff[i];
        int idx = lower_bound(all(pref_cnt), T.size() - already) - pref_cnt.begin();
        ans += N - idx;
    }

    cout << ans << endl;
}