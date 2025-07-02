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
    vector<int> a(N), b(N);
    rep(i, N) cin >> a[i];
    rep(i, N) cin >> b[i];

    int max_a = -1;
    vector<int> c(N);
    rep(i, N) {
        max_a = max(max_a, a[i]);
        c[i] = max_a * b[i];
    }

    int max_c = -1;
    rep(i, N) {
        max_c = max(max_c, c[i]);
        cout << max_c << endl;
    }
}
