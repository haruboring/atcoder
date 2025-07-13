#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    rep(i, M) cin >> A[i] >> B[i];

    vector<vector<int>> G(N, vector<int>(0));
    rep(i, M) {
        G[A[i] - 1].push_back(B[i] - 1);
        G[B[i] - 1].push_back(A[i] - 1);
    }

    rep(i, N) {
        set<int> f, s;
        f.insert(i);
        for (int fr : G[i]) f.insert(fr);

        for (int fr : G[i]) {
            for (int nfr : G[fr]) {
                if (f.count(nfr)) continue;
                s.insert(nfr);
            }
        }

        cout << s.size() << endl;
    }
}
