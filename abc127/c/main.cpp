#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M;
    cin >> N >> M;
    vector<int> L(M), R(M);
    rep(i, M) cin >> L[i] >> R[i];

    int ma = -1, mi = 1e9;
    rep(i, M) {
        ma = max(ma, L[i]);
        mi = min(mi, R[i]);
    }

    cout << max(0LL, mi - ma + 1) << endl;
}
