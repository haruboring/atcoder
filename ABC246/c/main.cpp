#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, K, X;
    cin >> N >> K >> X;
    vector<int> A(N);
    rep(i, N) {
        cin >> A[i];
    }
    sort(all(A));
    reverse(all(A));
    rep(i, N) {
        int used = (min(A[i] / X, K));
        A[i] = max(0LL, A[i] - (X * used));
        K -= used;
    }
    sort(all(A));
    reverse(all(A));
    rep(i, N) {
        if (i < K) {
            A[i] = 0;
        }
    }
    int ans = 0;
    rep(i, N) {
        ans += A[i];
    }
    cout << ans << endl;
}