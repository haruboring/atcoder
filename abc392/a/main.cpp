#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    vector<int> A(3);
    rep(i, 3) cin >> A[i];

    sort(all(A));

    if (A[0] * A[1] == A[2]) {
        cout << "Yes" << endl;
        return 0;
    } else {
        cout << "No" << endl;
    }
}
