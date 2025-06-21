#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, Q;
    cin >> N >> Q;

    vector<tuple<int, int, string>> qq(Q);
    rep(i, Q) {
        int f;
        cin >> f;
        if (f == 1) {
            int p;
            cin >> p;
            qq[i] = {f, p, ""};
        } else if (f == 2) {
            int p;
            string s;
            cin >> p >> s;
            qq[i] = {f, p, s};
        } else if (f == 3) {
            int p;
            cin >> p;
            qq[i] = {f, p, ""};
        }
    }

    vector<string> S(N + 1);

    string ans = "";
    int a = 0;
    for (int i = Q - 1; i >= 0; i--) {
        auto [f, p, s] = qq[i];
        if (f == 1) {
            if (p == a) a = 0;
        } else if (f == 2) {
            reverse(all(s));
            if (p == a) ans += s;
            // debug(ans);
        } else if (f == 3) {
            if (a == 0) {
                a = p;
            }
        }
    }

    reverse(all(ans));
    cout << ans << endl;
}
