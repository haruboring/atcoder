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
    vector<string> S(N), T(M);
    rep(i, N) cin >> S[i];
    rep(i, M) cin >> T[i];

    for (int i = 0; i < N - M + 1; i++) {
        for (int j = 0; j < N - M + 1; j++) {
            bool ok = true;
            for (int k = 0; k < M; k++) {
                for (int l = 0; l < M; l++) {
                    if (S[i + k][j + l] != T[k][l]) {
                        ok = false;
                    }
                }
            }
            if (ok) {
                cout << i + 1 << " " << j + 1 << endl;
                return 0;
            }
        }
    }
}
