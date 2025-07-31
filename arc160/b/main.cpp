#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using mint = atcoder::modint998244353;

signed main() {
    int T;
    cin >> T;
    rep(_, T) {
        int N;
        cin >> N;

        mint ans = 0;
        // x < y < z;
        for (int y = 1; y * y <= N; y++) ans += (N / y - y) * (y - 1) * 6;
        // x < y = z;
        for (int y = 1; y * y <= N; y++) ans += (y - 1) * 3;
        // x = y < z;
        for (int y = 1; y * y <= N; y++) ans += (N / y - y) * 3;
        // x = y = z;
        for (int y = 1; y * y <= N; y++) ans++;

        cout << ans.val() << endl;
    }
}
