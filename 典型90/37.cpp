#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int op(int a, int b) { return max(a, b); }
int e() { return -1e9; }
int mapping(int a, int b) { return max(a, b); }
int composition(int a, int b) { return max(a, b); }
int id() { return -1e9; }

signed main() {
    int W, N;
    cin >> W >> N;
    vector<int> L(N), R(N), V(N);
    rep(i, N) cin >> L[i] >> R[i] >> V[i];

    atcoder::lazy_segtree<int, op, e, int, mapping, composition, id> seg(W + 1);
    rep(i, W + 1) seg.set(i, -1);
    seg.set(0, 0);

    rep(i, N) {
        int l = L[i], r = R[i], v = V[i];
        for (int j = W; j >= 0; j--) {
            if (seg.get(j) == -1) continue;
            if (j + l > W) continue;
            int h = seg.get(j) + v;
            seg.apply(j + l, min(j + r, W) + 1, h);
        }
    }

    cout << seg.get(W) << endl;
}
