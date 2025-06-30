#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int A, V, B, W, T;
    cin >> A >> V >> B >> W >> T;
    if (V <= W) {
        cout << "NO" << endl;
        return 0;
    }

    if ((abs(A - B) + V - W - 1) / (V - W) <= T) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
