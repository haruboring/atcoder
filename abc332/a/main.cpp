#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, S, K;
    cin >> N >> S >> K;
    vector<int> P(N), Q(N);
    rep(i, N) cin >> P[i] >> Q[i];

    int ans = 0;
    rep(i, N) ans += P[i] * Q[i];

    if (ans < S) ans += K;

    cout << ans << endl;
}
