#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int A, M, L, R;
    cin >> A >> M >> L >> R;

    L -= A;
    R -= A;

    if (L > 0) {
        cout << R / M - (L - 1) / M << endl;
        return 0;
    }

    if (R < 0) {
        swap(L, R);
        L = -L;
        R = -R;
        cout << R / M - (L - 1) / M << endl;
        return 0;
    }

    cout << R / M + abs(L) / M + 1 << endl;
}
