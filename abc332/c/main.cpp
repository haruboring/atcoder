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
    string S;
    cin >> S;

    int ans = 0;
    int cnt_1 = 0, cnt_2 = 0;
    rep(i, N) {
        if (S[i] == '1') {
            cnt_1++;
        } else if (S[i] == '2') {
            cnt_2++;
        }

        if (i == N - 1 || S[i] == '0') {
            ans = max(ans, cnt_2 + max(0LL, cnt_1 - M));

            cnt_1 = 0;
            cnt_2 = 0;
        }
    }

    cout << ans << endl;
}
