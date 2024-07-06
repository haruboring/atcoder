#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, L, R;
    cin >> N >> L >> R;

    rep(i, L - 1) {
        cout << i + 1 << " ";
    }
    rep(i, R + 1 - L) {
        cout << R - i << " ";
    }
    repp(i, R, N) {
        cout << i + 1 << " ";
    }
    cout << endl;
}
