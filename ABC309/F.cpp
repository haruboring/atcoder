#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int op(int a, int b) { return min(a, b); }
int e() { return 1e9; }

int main() {
    int N;
    cin >> N;
    vector<vector<int>> X(N);
    rep(i, N) {
        vector<int> x(3);
        cin >> x[0] >> x[1] >> x[2];
        sort(all(x));
        X[i] = x;
    }

    rep(i, 3) {
        vector<int> tmp(N);
        rep(j, N) tmp[j] = X[j][i];
        sort(all(tmp));
        tmp.erase(unique(all(tmp)), tmp.end());
        rep(j, N) {
            int d = distance(tmp.begin(), lower_bound(all(tmp), X[j][i]));
            X[j][i] = d;
            if (i == 1) X[j][i] *= -1;
        }
    }
    sort(all(X));

    atcoder::segtree<int, op, e> seg(N);
    rep(i, N) {
        int a = -X[i][1], b = X[i][2];
        if (seg.prod(0, a) < b) {
            cout << "Yes" << endl;
            return 0;
        }
        seg.set(a, min(seg.get(a), b));
    }

    cout << "No" << endl;
}
