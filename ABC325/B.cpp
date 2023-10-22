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
    vector<int> W(N), X(N);
    rep(i, N) cin >> W[i] >> X[i];

    int ans = -1;
    rep(i, 24) {
        int tmp = 0;
        rep(j, N) {
            if (9 <= (X[j] + i) % 24 && (X[j] + i) % 24 <= 17) {
                tmp += W[j];
            }
        }
        ans = max(ans, tmp);
    }

    cout << ans << endl;
}