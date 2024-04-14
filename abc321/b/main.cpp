#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, X;
    cin >> N >> X;
    vector<int> A(N - 1);
    rep(i, N - 1) cin >> A[i];

    sort(all(A));

    int sum = 0;
    rep(i, N - 1) {
        sum += A[i];
    }

    int mi = A[0];
    int ma = A[N - 2];

    rep(i, 101) {
        if (mi <= i && i <= ma) {
            if (sum - mi - ma + i >= X) {
                cout << i << endl;
                return 0;
            }
        }
        if (i < mi) {
            if (sum - ma >= X) {
                cout << i << endl;
                return 0;
            }
        }
        if (ma < i) {
            if (sum - mi >= X) {
                cout << i << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;
}