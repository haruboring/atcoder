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
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    int ans = N + N - 1;
    int ren = 2;
    rep(i, N - 2) {
        if (A[i + 2] == A[i + 1] + (A[i + 1] - A[i])) {
            ren++;
        } else {
            ans += ren * (ren - 1) / 2;
            ans -= ren - 1;
            ren = 2;
        }
    }

    if (ren > 2) ans += ren * (ren - 1) / 2 - ren + 1;

    cout << ans << endl;
}
