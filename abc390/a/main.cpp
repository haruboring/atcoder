#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    vector<int> A(5);
    rep(i, 5) cin >> A[i];
    rep(i, 4) {
        vector<int> B = A;
        swap(B[i], B[i + 1]);
        bool ok = true;
        rep(i, 5) {
            if (B[i] != i + 1) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
}
