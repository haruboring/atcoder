#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int K, N, M;
    cin >> K >> N >> M;
    vector<int> A(K);
    rep(i, K) cin >> A[i];

    int t = M;
    debug("ok");
    vector<int> B(K);
    vector<pair<int, int>> P(K);
    rep(i, K) {
        B[i] = A[i] * M / N;
        t -= B[i];
        P[i] = make_pair(abs(N * (B[i] + 1) - M * A[i]) - abs(N * (B[i]) - M * A[i]), i);
    }
    debug(B[0]);
    sort(all(P));
    debug(t);
    rep(i, t) B[P[i].second]++;

    rep(i, K) cout << B[i] << " ";
    cout << endl;
}
