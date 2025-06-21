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
    vector<int> D(N - 1);
    rep(i, N - 1) cin >> D[i];

    vector<int> X(N);
    rep(i, N - 1) {
        X[i + 1] = X[i] + D[i];
    }

    rep(i, N - 1) {
        repp(j, i + 1, N) {
            cout << abs(X[j] - X[i]) << endl;
        }
    }
}
