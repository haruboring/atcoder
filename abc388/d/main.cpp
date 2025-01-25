#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int op(int a, int b) { return a + b; }
int e() { return 0; }
int mapping(int f, int x) { return f + x; }
int composition(int f, int g) { return f + g; }
int id() { return 0; }

signed main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    atcoder::lazy_segtree<int, op, e, int, mapping, composition, id> seg(N);
    rep(i, N) seg.set(i, A[i]);
    rep(i, N) {
        int a = seg.get(i);
        int b = min(N - i - 1, a);
        seg.apply(i + 1, i + b + 1, 1);
        seg.set(i, a - b);
    }

    rep(i, N) cout << seg.get(i) << " ";
    cout << endl;
}
