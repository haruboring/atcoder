#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, C;
    cin >> N >> C;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    vector<int> sum(N);
    multiset<int> ssum;
    ssum.insert(0);
    if (C > 0) {
        int ans = A[0];
        rep(i, N) {
            if (i != 0) sum[i] = sum[i - 1];
            sum[i] += A[i];

            if (i != 0) {
                ans = max(ans, sum[i] - *begin(ssum));
            }

            ssum.insert(sum[i]);
        }

        int su = 0;
        rep(i, N) su += A[i];

        cout << max(su, su + (C - 1) * ans) << endl;
    } else {
        int ans = A[0];
        rep(i, N) {
            if (i != 0) sum[i] = sum[i - 1];
            sum[i] += A[i];

            if (i != 0) {
                ans = min(ans, sum[i] - *rbegin(ssum));
            }

            ssum.insert(sum[i]);
        }

        int su = 0;
        rep(i, N) su += A[i];

        cout << max(su, su + (C - 1) * ans) << endl;
    }
}
