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

    int s = 0;
    int kabu = 0;
    int c = 1000;
    rep(i, N - 1) {
        if (A[i] < A[i + 1]) {
            kabu += c / A[i];
            c -= A[i] * (c / A[i]);
        } else {
            c += A[i] * kabu;
            kabu = 0;
        }
    }

    c += kabu * A[N - 1];

    cout << c << endl;
}
