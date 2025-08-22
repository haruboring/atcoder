#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using mint = atcoder::modint998244353;

int op(int a, int b) { return a + b; }
int e() { return 0; }

signed main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    vector<mint> ans(N);
    vector<int> cA = A;
    sort(all(cA));

    vector<int> t(N, 1);
    atcoder::segtree<int, op, e> seg(cA), seg_idx(t);

    mint sum = 0;
    rep(i, N) sum += cA[i] * (2 * i + 1);

    map<int, int> m;  // 重複対応

    for (int i = N - 1; i >= 0; i--) {
        ans[i] = sum / ((mint)(i + 1) * (i + 1));
        int idx = lower_bound(all(cA), A[i]) - cA.begin();
        m[idx]++;
        idx += m[idx] - 1;

        int exist_idx = seg_idx.prod(0, idx + 1);
        sum -= (mint)A[i] * (2 * exist_idx - 1);
        seg_idx.set(idx, 0);
        seg.set(idx, 0);
        sum -= 2 * seg.prod(idx, N);

        // debug(i);
    }

    rep(i, N) cout << ans[i].val() << endl;
}
