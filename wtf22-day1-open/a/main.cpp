#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M, A, B;
    cin >> N >> M >> A >> B;
    vector<int> X(M);
    rep(i, M) cin >> X[i];

    vector<int> c(N);
    rep(i, M) c[X[i] - 1]++;
    sort(all(c));

    int ans = max(0LL, N + B - A);
    int t = 0;
    rep(i, N) {
        t += c[i];
        if (t <= B) ans = max(ans, i + 1);
    }

    cout << ans << endl;
}
