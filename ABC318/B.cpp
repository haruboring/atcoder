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
    vector<int> A(N), B(N), C(N), D(N);
    rep(i, N) cin >> A[i] >> B[i] >> C[i] >> D[i];

    vector<vector<int>> d(100 + 10, vector<int>(100 + 10, 0));
    rep(i, N) {
        d[A[i]][C[i]]++;
        d[A[i]][D[i]]--;
        d[B[i]][C[i]]--;
        d[B[i]][D[i]]++;
    }

    vector<vector<int>> s(100 + 10, vector<int>(100 + 10, 0));
    rep(i, 100 + 10) {
        rep(j, 100 + 10) {
            if (j == 0)
                s[i][j] = d[i][j];
            else
                s[i][j] = s[i][j - 1] + d[i][j];
        }
    }

    vector<vector<int>> t(100 + 10, vector<int>(100 + 10, 0));
    rep(j, 100 + 10) {
        rep(i, 100 + 10) {
            if (i == 0)
                t[i][j] = s[i][j];
            else
                t[i][j] = t[i - 1][j] + s[i][j];
        }
    }

    int cn = 0;
    rep(i, 100 + 10) {
        rep(j, 100 + 10) {
            if (t[i][j] > 0) cn++;
        }
    }

    cout << cn << endl;
}