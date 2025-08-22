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
    vector<int> R(N), C(N);
    rep(i, N) cin >> R[i] >> C[i];

    vector<int> sR = R, sC = C;
    sort(all(sR)), sort(all(sC));
    int x = sR[0] + (sR[N - 1] - sR[0]) / 2, y = sC[0] + (sC[N - 1] - sC[0]) / 2;

    int ans = -1;
    debug(x);
    debug(y);
    rep(i, N) ans = max(ans, abs(R[i] - x) + max(0LL, abs(C[i] - y) - abs(R[i] - x)));
    cout << ans << endl;
}
