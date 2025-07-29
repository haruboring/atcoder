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
    string S;
    cin >> S;

    map<int, vector<int>> m;
    rep(i, N) m[S[i] - '0'].push_back(i);
    rep(i, 10) m[i].push_back(1e18);

    int cnt = 0;
    rep(a, 10) {
        int ai = m[a][0];
        if (ai == 1e18) continue;
        rep(b, 10) {
            int bi = *upper_bound(all(m[b]), ai);
            if (bi == 1e18) continue;
            rep(c, 10) {
                int ci = *upper_bound(all(m[c]), bi);
                if (ci == 1e18) continue;
                cnt++;
            }
        }
    }

    cout << cnt << endl;
}
