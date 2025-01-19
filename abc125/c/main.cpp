#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int op(int a, int b) { return gcd(a, b); }
int e() { return 0; }

signed main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    debug(gcd(2, 0));

    atcoder::segtree<int, op, e> seg(A);

    debug(seg.get(1));

    int ans = -1;
    rep(i, N) {
        int l = seg.prod(0, i);
        int r = seg.prod(i + 1, N);
        if (l == 0 || r == 0) {
            l = max(l, r);
            r = max(l, r);
        }

        ans = max(ans, gcd(l, r));
    }

    cout << ans << endl;
}
