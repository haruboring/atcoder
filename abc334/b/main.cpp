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

    L -= A, R -= A;
    int r = M * (R / M);
    if (R < 0 && R % M != 0) r -= M;
    int l = M * ((L + M - 1) / M);
    if (L < 0 && (L + M - 1) % M != 0) l -= M;

    if (l > r) {
        cout << 0 << endl;
    } else {
        cout << (r - l) / M + 1 << endl;
    }
}
