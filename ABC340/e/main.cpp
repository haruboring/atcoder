#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int op(int a, int b) { return min(a, b); }
int e() { return 1e18; }
int mapping(int f, int x) { return f + x; }
int composition(int f, int g) { return f + g; }
int id() { return 0; }

signed main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    vector<int> B(M);
    rep(i, M) cin >> B[i];

    atcoder::lazy_segtree<int, op, e, int, mapping, composition, id> seg(A);

    rep(i, M) {
        int ball = seg.get(B[i]);
        seg.set(B[i], 0);
        int all = ball / N;
        int rem = ball % N;
        int s = (B[i] + 1) % N;
        int t = (B[i] + 1 + rem) % N;

        seg.apply(0, N, all);
        if (s < t) {
            seg.apply(s, t, 1);
        } else {
            if (s == t) continue;

            seg.apply(s, N, 1);
            seg.apply(0, t, 1);
        }
    }

    rep(i, N) {
        cout << seg.get(i) << " ";
    }
    cout << endl;
}
