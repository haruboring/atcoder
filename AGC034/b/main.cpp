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
    int cnt_A = 0;
    rep(i, N) {
        if (S[i] == 'A') {
            cnt_A++;
        } else if (i + 1 < N && S[i] == 'B' && S[i + 1] == 'C') {
            ans += cnt_A;
            i++;
        } else {
            cnt_A = 0;
        }
    }

    cout << ans << endl;
}
