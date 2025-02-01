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
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    int pre = S[0].size();
    rep(i, N - 1) {
        while (S[i + 1].size() < pre) {
            S[i + 1] += "*";
            // debug(S[i + 1]);
        }
        pre = S[i + 1].size();
    }

    int M = 0;
    rep(i, N) M = max(M, (int)S[i].size());

    vector<string> U(M, "");
    rep(i, N) {
        rep(j, S[N - 1 - i].size()) {
            U[j] += S[N - 1 - i][j];
        }
    }

    rep(i, M) cout << U[i] << endl;
}
