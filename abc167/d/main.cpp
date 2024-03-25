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
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    rep(i, N) A[i]--;

    vector<vector<int>> dub(N, vector<int>(64, -1));
    rep(i, N) dub[i][0] = A[i];
    repp(i, 1, 64) {
        rep(j, N) {
            dub[j][i] = dub[dub[j][i - 1]][i - 1];
        }
    }

    int ans = 0;
    for (int i = 62; i >= 0; i--) {
        if (K & (1LL << i)) {
            ans = dub[ans][i];
        }
    }

    cout << ans + 1 << endl;
}
