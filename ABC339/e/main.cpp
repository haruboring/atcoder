#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int op(int a, int b) { return max(a, b); }
int e() { return 0; }

signed main() {
    int N, D;
    cin >> N >> D;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    atcoder::segtree<int, op, e> dp(1000000 + 100);
    dp.set(A[0], 1);
    repp(i, 1, N) {
        int l = max(0LL, A[i] - D);
        int r = min(1000000LL - 1LL, A[i] + D);

        dp.set(A[i], dp.prod(l, r + 1) + 1);
    }

    cout << dp.all_prod() << endl;
}
