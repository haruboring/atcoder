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
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    map<int, int> m;
    rep(i, N) {
        int cnt = 0;
        rep(j, M) if (S[i][j] == '1') cnt++;
        m[cnt % 2]++;
    }

    int ans = m[0] * m[1];
    cout << ans << endl;
}
