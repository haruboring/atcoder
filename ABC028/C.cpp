#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    vector<int> A(5);
    rep(i, 5) {
        cin >> A[i];
    }
    vector<int> ans(0);
    rep(i, 3) {
        repp(j, i + 1, 4) {
            repp(k, j + 1, 5) {
                ans.push_back(A[i] + A[j] + A[k]);
            }
        }
    }
    sort(all(ans));
    reverse(all(ans));
    cout << ans[2] << endl;
}