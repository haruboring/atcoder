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
    vector<int> A(N + 1), C(N + M + 1);
    rep(i, N + 1) cin >> A[i];
    rep(i, N + M + 1) cin >> C[i];

    int l = 0;
    rep(i, N + 1) {
        if (A[i] != 0) {
            l = i;
            break;
        }
    }

    vector<int> B(M + 1);
    repp(i, l, M + 1 + l) {
        B[i - l] = C[i] / A[l];
        rep(j, N + 1) {
            C[i + j - l] -= B[i - l] * A[j];
        }
    }

    rep(i, M + 1) cout << B[i] << " ";
    cout << endl;
}
