#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    int Q;
    cin >> Q;
    vector<int> L(Q), R(Q), X(Q);
    rep(i, Q) cin >> L[i] >> R[i] >> X[i];
    debug(N);

    map<int, vector<int>> m;
    rep(i, N) {
        m[A[i]].push_back(i + 1);
    }

    rep(i, Q) {
        auto idx1 = upper_bound(all(m[X[i]]), R[i]);
        auto idx2 = lower_bound(all(m[X[i]]), L[i]);

        if (idx2 == m[X[i]].end()) {
            cout << 0 << endl;
        } else {
            cout << idx1 - idx2 << endl;
        }
    }
}
