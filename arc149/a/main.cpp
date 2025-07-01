#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M;
    cin >> N >> M;

    vector<string> S(0);
    vector<pair<int, int>> v;
    for (int k = 9; k > 0; k--) {
        int amari = 0;
        rep(i, N) {
            amari = 10 * amari + k;
            amari %= M;
            if (amari == 0) v.push_back({i + 1, k});
        }
    }

    if (v.size() == 0) {
        cout << -1 << endl;
        return 0;
    }

    sort(all(v)), reverse(all(v));

    auto [c, k] = v[0];
    rep(_, c) cout << k;
    cout << endl;
}
