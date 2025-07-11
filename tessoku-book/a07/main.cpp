#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int D, N;
    cin >> D >> N;
    vector<int> L(N), R(N);
    rep(i, N) cin >> L[i] >> R[i];

    vector<int> A(D + 1);
    rep(i, N) A[L[i] - 1]++, A[R[i]]--;
    rep(i, D) A[i + 1] += A[i];

    rep(i, D) {
        cout << A[i] << endl;
    }
}
