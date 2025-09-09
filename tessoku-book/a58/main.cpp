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
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    atcoder::segtree<int, op, e> seg(A);
    rep(i, Q) {
        int f, x, y;
        cin >> f >> x >> y;

        if (f == 1) {
            seg.set(x - 1, y);
        } else {
            cout << seg.prod(x - 1, y - 1) << endl;
        }
    }
}
