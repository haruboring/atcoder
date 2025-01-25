#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, C;
    cin >> N >> C;
    vector<int> s(N), t(N), c(N);
    rep(i, N) cin >> s[i] >> t[i] >> c[i];

    vector<int> ns(0), nt(0);
    repp(cc, 1, C + 1) {
        vector<int> tmp(1e5 + 10);
        rep(i, N) {
            if (c[i] != cc) continue;
            tmp[s[i]]++;
            tmp[t[i]]--;
        }

        int ss = -1;
        rep(i, 1e5 + 5) {
            if (tmp[i] == 1) {
                ss = i;
            }
            if (tmp[i] == -1) {
                ns.push_back(ss);
                nt.push_back(i);
            }
        }
    }

    s = ns, t = nt;
    debug(s.size());

    vector<int> v(2 * 1e5 + 10);
    rep(i, s.size()) {
        v[2 * s[i] - 1]++;
        v[2 * t[i]]--;
    }
    rep(i, 2 * 1e5 + 5) v[i + 1] = v[i] + v[i + 1];

    int ans = -1;
    rep(i, 2 * 1e5 + 5) ans = max(ans, v[i]);

    cout << ans << endl;
}
