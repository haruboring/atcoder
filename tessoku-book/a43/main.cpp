#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, L;
    cin >> N >> L;
    vector<int> A(N);
    vector<char> B(N);
    rep(i, N) cin >> A[i] >> B[i];

    int ans = -1;
    rep(i, N) {
        if (B[i] == 'E') {
            ans = max(ans, L - A[i]);
        } else {
            ans = max(ans, A[i]);
        }
    }
    cout << ans << endl;
}
