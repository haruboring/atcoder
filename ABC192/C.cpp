#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, K;
    cin >> N >> K;

    int ans = N;
    rep(i, K) {
        string g1 = to_string(ans);
        sort(all(g1));
        string g2 = g1;
        reverse(all(g2));
        ans = stoll(g2) - stoll(g1);
    }

    cout << ans << endl;
}