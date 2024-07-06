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

    multiset<int> S;
    int ans = 1e18;
    sort(all(A));
    rep(i, N - K) {
        S.insert(A[i]);
    }
    ans = *S.rbegin() - *S.begin();
    rep(i, K) {
        S.insert(A[i + N - K]);
        S.erase(S.find(A[i]));
        ans = min(ans, *S.rbegin() - *S.begin());
    }

    cout << ans << endl;
}
