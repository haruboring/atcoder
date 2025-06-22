#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int A, B;
    cin >> A >> B;

    repp(x, -101, 101) repp(y, -101, 101) if ((x + y == A) && (x - y == B)) {
        cout << x << " " << y << endl;
        return 0;
    }
}
