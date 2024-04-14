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
    vector<int> H(N);
    rep(i, N) cin >> H[i];
    vector<int> A(M), B(M);
    rep(i, M) cin >> A[i] >> B[i];

    rep(i, M) A[i]--, B[i]--;

    vector<vector<int>> G(N);
    rep(i, M) {
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    int ans = 0;
    rep(i, N) {
        bool ok = true;
        for (int j : G[i]) {
            if (H[i] <= H[j]) {
                ok = false;
                break;
            }
        }
        if (ok) ans++;
    }

    cout << ans << endl;
}
