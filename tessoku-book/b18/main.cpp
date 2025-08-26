#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, S;
    cin >> N >> S;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    vector<vector<bool>> dp(N + 1, vector<bool>(S + 1, false));
    dp[0][0] = true;
    rep(i, N) {
        rep(j, S + 1) {
            if (dp[i][j] == false) continue;
            dp[i + 1][j] = true;
            if (j + A[i] > S) continue;
            dp[i + 1][j + A[i]] = true;
        }
    }

    if (dp[N][S] == false) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> c;
    int i = N, s = S;
    while (1) {
        if (s - A[i - 1] >= 0 && dp[i - 1][s - A[i - 1]]) {
            c.push_back(i);
            s -= A[i - 1];
        }
        i--;
        if (i == 0) break;
    }

    sort(all(c));
    cout << c.size() << endl;
    rep(i, c.size()) cout << c[i] << " ";
    cout << endl;
}
