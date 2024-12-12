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

    rep(cnt, 100000) {
        sort(all(A));
        reverse(all(A));
        if (A[1] <= 0) {
            cout << cnt << endl;
            return 0;
        }
        A[0]--, A[1]--;
    }
}
