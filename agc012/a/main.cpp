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
    vector<int> A(3 * N);
    rep(i, 3 * N) cin >> A[i];

    sort(all(A));
    reverse(all(A));

    int ans = 0;
    rep(i, N) ans += A[2 * i + 1];

    cout << ans << endl;
}
