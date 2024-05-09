#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

template <class Abel>
struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<Abel> diff_weight;

    UnionFind(int n = 1, Abel SUM_UNITY = 0) {
        init(n, SUM_UNITY);
    }

    void init(int n = 1, Abel SUM_UNITY = 0) {
        par.resize(n);
        rank.resize(n);
        diff_weight.resize(n);
        for (int i = 0; i < n; ++i) {
            par[i] = i;
            rank[i] = 0;
            diff_weight[i] = SUM_UNITY;
        }
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        } else {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }

    Abel weight(int x) {
        root(x);
        return diff_weight[x];
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y, Abel w) {
        w += weight(x);
        w -= weight(y);
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y), w = -w;
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        diff_weight[y] = w;
        return true;
    }

    Abel diff(int x, int y) {
        return weight(y) - weight(x);
    }
};

signed main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(Q), B(Q), D(Q);
    rep(i, Q) cin >> A[i] >> B[i] >> D[i];

    rep(i, Q) A[i]--, B[i]--;

    UnionFind<int> uf(N);
    vector<int> ans;
    rep(i, Q) {
        if (!uf.issame(A[i], B[i])) {
            uf.merge(A[i], B[i], -D[i]);
            ans.push_back(i + 1);
        } else {
            if (uf.diff(A[i], B[i]) == -D[i]) {
                ans.push_back(i + 1);
            }
        }
    }

    rep(i, ans.size()) cout << ans[i] << " ";

    cout << endl;
}
