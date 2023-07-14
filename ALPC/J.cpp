#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int op(int a, int b) { return max(a, b); }
int e() { return -1; }
int target;
bool comp(int a) { return a < target; }

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    atcoder::segtree<int, op, e> seg(A);
    rep(_, Q) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            seg.set(x - 1, y);
        } else if (t == 2) {
            cout << seg.prod(x - 1, y) << endl;
        } else {
            target = y;
            cout << seg.max_right<comp>(x - 1) + 1 << endl;
        }
    }
}
