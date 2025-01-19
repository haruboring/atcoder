// #include "atcoder/all"
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
    int Q;
    cin >> Q;
    vector<int> X(Q), K(Q);
    rep(i, Q) cin >> X[i] >> K[i];

    vector<vector<int>> G(N, vector<int>(0));
    rep(i, M) {
        G[A[i] - 1].push_back(B[i] - 1);
        G[B[i] - 1].push_back(A[i] - 1);
    }

    rep(i, Q) {
        set<int> visits;
        queue<pair<int, int>> q;
        q.push({X[i] - 1, 0});
        int sum = 0;
        while (!q.empty()) {
            auto [a, d] = q.front();
            q.pop();
            if (visits.count(a)) continue;
            visits.insert(a);
            sum += a + 1;

            for (auto na : G[a]) {
                if (visits.count(na)) continue;
                if (d + 1 > K[i]) continue;
                q.push({na, d + 1});
            }
        }

        cout << sum << endl;
    }
}