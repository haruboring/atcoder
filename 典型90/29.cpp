#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int op(int a, int b) { return max(a, b); }
int e() { return 0; }
int mapping(int a, int b) { return max(a, b); }
int composition(int a, int b) { return max(a, b); }
int id() { return 0; }

int main() {
    int W, N;
    cin >> W >> N;
    vector<int> L(N), R(N);
    rep(i, N) cin >> L[i] >> R[i];

    atcoder::lazy_segtree<int, op, e, int, mapping, composition, id> seg(W);
    rep(i, N) {
        int l = L[i], r = R[i];
        int h = seg.prod(l - 1, r) + 1;
        cout << h << endl;
        seg.apply(l - 1, r, h);
    }
}