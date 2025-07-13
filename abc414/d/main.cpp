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
    vector<int> X(N);
    rep(i, N) cin >> X[i];

    sort(all(X));
    int ans = X[N - 1] - X[0];
    debug(ans);
    vector<int> D(N - 1);
    rep(i, N - 1) D[i] = X[i + 1] - X[i];
    sort(all(D));
    reverse(all(D));
    rep(i, M - 1) {
        ans -= D[i];
    }

    cout << ans << endl;
}
