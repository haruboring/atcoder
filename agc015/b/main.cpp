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
    rep(i, N) {
        if (S[i] == 'U') {
            ans += (N - i - 1);
            ans += 2 * i;
        } else {
            ans += i;
            ans += 2 * (N - i - 1);
        }
    }

    cout << ans << endl;
}
