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
    int Q;
    cin >> Q;
    vector<int> X(Q);
    rep(i, Q) cin >> X[i];

    A.push_back(1e18);
    A.push_back(-1e18);
    sort(all(A));
    rep(i, Q) {
        int l = 0, r = N + 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (A[m] >= X[i]) {
                r = m;
            } else {
                l = m;
            }
        }
        cout << r - 1 << endl;
    }
}
