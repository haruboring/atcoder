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
    vector<int> H(N);
    rep(i, N) cin >> H[i];

    vector<int> c(N, 1e18);
    c[0] = 0;
    rep(i, N - 1) {
        c[i + 1] = min(c[i + 1], c[i] + abs(H[i + 1] - H[i]));
        if (i < N - 2) c[i + 2] = min(c[i + 2], c[i] + abs(H[i + 2] - H[i]));
    }
    cout << c[N - 1] << endl;
}
