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
    vector<int> S(N);
    rep(i, N) cin >> S[i];

    rep(i, N) {
        if (S[i] == 0) {
            cout << N << endl;
            return 0;
        }
    }

    int ans = 0;

    int tmp = 1;
    int r = 0;
    rep(l, N) {
        while (r < N && tmp * S[r] <= K) {
            tmp *= S[r];
            r++;
        }
        ans = max(ans, r - l);
        if (l == r)
            r++;
        else
            tmp /= S[l];
    }

    cout << ans << endl;
}