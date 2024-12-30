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

    int MOD = 1000000000 + 7;
    int ans = 1;

    int tmp = 1;
    rep(i, N - 1) {
        if (S[i] != S[i + 1]) {
            tmp++;
        } else {
            ans *= (tmp + 1) / 2;
            ans %= MOD;
            tmp = 1;
        }
    }
    ans *= (tmp + 1) / 2;
    ans %= MOD;

    cout << ans << endl;
}
