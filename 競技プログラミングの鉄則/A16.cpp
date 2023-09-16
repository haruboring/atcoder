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
    vector<int> A(N + 1), B(N + 1), C(N + 1);
    rep(i, N - 1) {
        cin >> A[i + 2];
    }
    rep(i, N - 2) {
        cin >> B[i + 3];
    }
    C[2] = A[2];
    repp(i, 3, N + 1) {
        C[i] = min(C[i - 2] + B[i], C[i - 1] + A[i]);
    }
    cout << C[N] << endl;
}