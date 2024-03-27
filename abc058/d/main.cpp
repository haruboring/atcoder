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
    vector<int> X(N), Y(M);
    rep(i, N) cin >> X[i];
    rep(i, M) cin >> Y[i];

    vector<int> S(N - 1), T(M - 1);
    rep(i, N - 1) S[i] = X[i + 1] - X[i];
    rep(i, M - 1) T[i] = Y[i + 1] - Y[i];

    mint std = 0;
    rep(i, N - 1) {
        std += S[i] * (i + 1) * (N - i - 1);
    }

    mint ans = 0;
    rep(i, M - 1) {
        ans += T[i] * (i + 1) * (M - i - 1) * std;
    }

    cout << ans.val() << endl;
}
