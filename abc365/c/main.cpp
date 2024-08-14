#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    int l = 0, r = 1e18;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        int cnt = 0;
        rep(i, N) {
            cnt += min(mid, A[i]);
        }
        if (cnt <= M) {
            l = mid;
        } else {
            r = mid;
        }
    }

    if (l > 1e17) {
        cout << "infinite" << endl;
        return 0;
    }
    cout << l << endl;
}
