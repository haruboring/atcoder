#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

// 区間加算・区間最小値取得
int op(int a, int b) { return min(a, b); }
int e() { return 1e18; }
int mapping(int f, int x) { return f + x; }
int composition(int f, int g) { return f + g; }
int id() { return 0; }

// 区間和
int op1(int a, int b) { return a + b; }
int e1() { return 0; }

signed main() {
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    vector<int> flag(Q), L(Q), R(Q);
    rep(i, Q) {
        cin >> flag[i] >> L[i] >> R[i];
        L[i]--;
        R[i]--;
    }

    atcoder::lazy_segtree<int, op, e, int, mapping, composition, id> seg(N);
    atcoder::segtree<int, op1, e1> seg1(N);

    int cnt = 0;
    rep(i, N) {
        if (S[i] == '(') {
            cnt++;
            seg.set(i, cnt);
            seg1.set(i, 1);
        } else {
            cnt--;
            seg.set(i, cnt);
            seg1.set(i, -1);
        }
    }

    rep(i, Q) {
        if (flag[i] == 1) {
            if (seg1.get(R[i]) == seg1.get(L[i])) continue;
            seg.apply(L[i], R[i], 2 * seg1.get(R[i]));
            int tmp = seg1.get(L[i]);
            seg1.set(L[i], seg1.get(R[i]));
            seg1.set(R[i], tmp);
        } else {
            int m = 0;
            if (L[i] > 0) m = seg.get(L[i] - 1);
            if (seg.prod(L[i], R[i] + 1) - m == 0 && seg1.prod(L[i], R[i] + 1) == 0) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
}
