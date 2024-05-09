#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M, D;
    cin >> N >> M >> D;
    vector<int> A(N), B(M);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];

    sort(all(A));
    sort(all(B));

    int sum = -1;

    rep(i, N) {
        int ind = lower_bound(all(B), A[i] + D) - B.begin();
        if (B[ind] != A[i] + D) {
            ind--;
        }

        if (abs(A[i] - B[ind]) <= D) {
            sum = max(sum, abs(A[i] + B[ind]));
        }
    }

    cout << sum << endl;
}