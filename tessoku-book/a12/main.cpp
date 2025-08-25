#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    int l = 0, r = 1e9;
    while (r - l > 1) {
        int m = (l + r) / 2;
        int cnt = 0;
        rep(i, N) cnt += m / A[i];

        if (cnt >= K) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << endl;
}
