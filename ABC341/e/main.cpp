#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

// 区間積
int op(int a, int b) {
    return a * b;
}
int e() { return 1; }

int op1(int a, int b) { return a * b; }
int e1() { return 1; }
int mapping1(int f, int x) { return f * x; }
int composition1(int f, int g) { return f * g; }
int id1() { return 1; }

signed main() {
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    vector<int> flag(Q), L(Q), R(Q);
    rep(i, Q) cin >> flag[i] >> L[i] >> R[i];
    rep(i, Q) L[i]--, R[i]--;

    vector<int> tmp(N - 1);
    rep(i, N - 1) {
        if (S[i] != S[i + 1]) tmp[i] = 1;
    }
    atcoder::segtree<int, op, e> seg(tmp);
    vector<int> tmp1(N);
    rep(i, N) {
        if (S[i] == '0')
            tmp1[i] = -1;
        else
            tmp1[i] = 1;
    }
    atcoder::lazy_segtree<int, op1, e1, int, mapping1, composition1, id1> seg1(tmp1);

    rep(i, Q) {
        if (flag[i] == 1) {
            seg1.apply(L[i], R[i] + 1, -1);
            if (L[i] > 0) {
                if (seg1.get(L[i] - 1) != seg1.get(L[i])) {
                    seg.set(L[i] - 1, 1);
                } else {
                    seg.set(L[i] - 1, 0);
                }
            }
            if (R[i] < N - 1) {
                if (seg1.get(R[i]) != seg1.get(R[i] + 1)) {
                    seg.set(R[i], 1);
                } else {
                    seg.set(R[i], 0);
                }
            }
        } else {
            if (seg.prod(L[i], R[i]) == 1)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
}
