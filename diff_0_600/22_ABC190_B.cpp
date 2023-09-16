#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, S, D;
    cin >> N >> S >> D;
    vector<int> X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];
    rep(i, N) {
        if (X[i] < S && Y[i] > D) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}