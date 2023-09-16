#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    vector<string> S(10);
    rep(i, 10) {
        cin >> S[i];
    }
    int A = 11, B = 0, C = 11, D = 0;
    rep(i, 10) {
        rep(j, 10) {
            if (S[i][j] == '#') {
                A = min(A, i + 1);
                B = max(B, i + 1);
                C = min(C, j + 1);
                D = max(D, j + 1);
            }
        }
    }
    cout << A << " " << B << endl;
    cout << C << " " << D << endl;
}