#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int op(int a, int b) { return a + b; }
int e() { return 1e18; }
int mapping(int f, int x) { return min(f, x); }
int composition(int f, int g) { return min(f, g); }
int id() { return 1e18; }

signed main() {
    int N, L, R;
    cin >> N >> L >> R;
    vector<int> X(N);
    rep(i, N) cin >> X[i];

    atcoder::lazy_segtree<int, op, e, int, mapping, composition, id> seg(N);
    seg.set(0, 0);
    rep(i, N - 1) {
        int posL = lower_bound(all(X), X[i] + L) - X.begin();
        int posR = upper_bound(all(X), X[i] + R) - X.begin();

        if (posL <= posR) seg.apply(posL, posR, seg.get(i) + 1);
    }

    cout << seg.get(N - 1) << endl;
}
