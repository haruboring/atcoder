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
    vector<int> B(M);
    rep(i, M) cin >> B[i];

    int l = 0, r = 1e10;
    while (r - l > 1) {
        int m = (l + r) / 2;
        int sell = 0, buy = 0;
        rep(i, N) if (A[i] <= m) sell++;
        rep(i, M) if (B[i] >= m) buy++;
        if (sell >= buy) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << endl;
}
