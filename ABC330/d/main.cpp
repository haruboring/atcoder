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
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    vector<int> row(N), col(N);
    rep(i, N) {
        int cnt = 0;
        rep(j, N) if (S[i][j] == 'o') cnt++;
        row[i] = cnt;

        cnt = 0;
        rep(j, N) if (S[j][i] == 'o') cnt++;
        col[i] = cnt;
    }

    int ans = 0;
    rep(i, N) {
        rep(j, N) {
            if (S[i][j] == 'x') continue;
            ans += (row[i] - 1) * (col[j] - 1);
        }
    }

    cout << ans << endl;
}
