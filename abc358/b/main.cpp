#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, A;
    cin >> N >> A;
    vector<int> T(N);
    rep(i, N) cin >> T[i];

    int ans = T[0] + A;
    rep(i, N - 1) {
        cout << ans << endl;
        ans = max(ans + A, T[i + 1] + A);
    }

    cout << ans << endl;
}