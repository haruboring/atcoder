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
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    vector<int> S(N - 1), T(N - 1);
    rep(i, N - 1) cin >> S[i] >> T[i];

    rep(i, N - 1) {
        A[i + 1] += (A[i] / S[i]) * T[i];
    }
    cout << A[N - 1] << endl;
}
