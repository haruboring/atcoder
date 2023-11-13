#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> X(N);
    rep(i, N) cin >> X[i];

    int ans = 0;
    rep(i, N - 1) {
        ans += min((X[i + 1] - X[i]) * A, B);
    }
    cout << ans << endl;
}