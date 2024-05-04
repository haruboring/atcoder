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

    int ans = 1e9;
    rep(i, S.size() - 2) {
        int si = stoll(S.substr(i, 3));
        ans = min(ans, abs(753 - si));
    }

    cout << ans << endl;
}