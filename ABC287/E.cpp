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
    cin >> N;
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    vector<string> T = S;

    sort(all(S));

    rep(i, N) {
        string s = T[i];

        int itr = lower_bound(all(S), s) - S.begin();

        int ans = 0;
        if (itr + 1 < N) {
            string t = S[itr + 1];
            int cnt = 0;
            rep(j, s.size()) {
                if (s[j] != t[j]) break;
                cnt++;
            }
            ans = max(ans, cnt);
        }
        if (itr - 1 >= 0) {
            string t = S[itr - 1];
            int cnt = 0;
            rep(j, s.size()) {
                if (s[j] != t[j]) break;
                cnt++;
            }
            ans = max(ans, cnt);
        }

        cout << ans << endl;
    }
}