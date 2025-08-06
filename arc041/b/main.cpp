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
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    vector<vector<int>> C(N, vector<int>(M));
    rep(i, N) rep(j, M) C[i][j] = S[i][j] - '0';
    vector<vector<int>> D(N, vector<int>(M));
    repp(i, 1, N - 1) repp(j, 1, M - 1) {
        int cnt = min({C[i + 1][j], C[i - 1][j], C[i][j + 1], C[i][j - 1]});
        C[i + 1][j] -= cnt;
        C[i - 1][j] -= cnt;
        C[i][j + 1] -= cnt;
        C[i][j - 1] -= cnt;
        D[i][j] = cnt;
    }

    rep(i, N) {
        rep(j, M) cout << D[i][j];
        cout << endl;
    }
}
