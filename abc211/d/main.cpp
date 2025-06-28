#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using mint = atcoder::modint1000000007;

signed main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    rep(i, M) cin >> A[i] >> B[i], A[i]--, B[i]--;

    vector<vector<int>> G(N, vector<int>(0));
    rep(i, M) {
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    map<pair<int, int>, int> m;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
    vector<int> D(N, 1e18);
    m[{-1, -1}] = 1;
    q.push({0, 0, -1});
    while (!q.empty()) {
        auto [d, v, pv] = q.top();
        q.pop();
        m[{v, d}] += m[{pv, d - 1}];
        m[{v, d}] %= 1000000000 + 7;
        if (d >= D[v]) continue;
        D[v] = d;

        for (int nv : G[v]) {
            if (d + 1 >= D[nv]) continue;
            q.push({d + 1, nv, v});
        }
    }

    cout << m[{N - 1, D[N - 1]}] << endl;
}
