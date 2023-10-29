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
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    sort(all(A));

    int ans = -1;

    rep(i, N) {
        int itr = lower_bound(all(A), A[i] + M) - A.begin();
        ans = max(ans, itr - i);
    }

    cout << ans << endl;
}