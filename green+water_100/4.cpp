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
    vector<double> A(N);
    rep(i, N) {
        cin >> A[i];
    }

    int l = 0, r = (1 << 30);
    while (r - l > 1) {
        int mid = (l + r) / 2;
        int cnt = 0;
        rep(i, N) {
            cnt += (A[i] + mid - 1) / mid - 1;
        }
        if (cnt <= K) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << endl;
}