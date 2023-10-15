#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    sort(all(A));

    rep(_, Q) {
        int K;
        cin >> K;

        int l = 0, r = 2e18;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            int itr = upper_bound(all(A), mid) - A.begin();

            if (mid - itr < K) {
                l = mid;
            } else {
                r = mid;
            }
        }

        cout << r << endl;
    }
}