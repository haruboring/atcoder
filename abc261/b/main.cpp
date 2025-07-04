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

    vector<vector<int>> A(N, vector<int>(N, 0));
    rep(i, N) {
        rep(j, N) {
            if (S[i][j] == 'W') {
                A[i][j] = 1;
            } else if (S[i][j] == 'L') {
                A[i][j] = -1;
            } else {
                A[i][j] = 0;
            }
        }
    }

    rep(i, N) {
        rep(j, N) {
            if (A[i][j] != -A[j][i]) {
                cout << "incorrect" << endl;
                return 0;
            }
        }
    }

    cout << "correct" << endl;
}
