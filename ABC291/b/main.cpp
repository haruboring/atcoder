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
    vector<int> X(5 * N);
    rep(i, 5 * N) cin >> X[i];

    sort(all(X));
    int ans = 0;
    repp(i, N, 5 * N - N) {
        ans += X[i];
    }
    cout << fixed << setprecision(19) << (double)ans / (3 * N) << endl;
}
