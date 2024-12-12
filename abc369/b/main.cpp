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
    vector<int> A(N);
    vector<string> S(N);
    rep(i, N) cin >> A[i] >> S[i];

    int pre_l = -1, pre_r = -1;
    int ans = 0;
    rep(i, N) {
        if (S[i] == "L") {
            if (pre_l != -1) {
                ans += abs(A[i] - pre_l);
            }
            pre_l = A[i];
        }
        if (S[i] == "R") {
            if (pre_r != -1) {
                ans += abs(A[i] - pre_r);
            }
            pre_r = A[i];
        }
    }

    cout << ans << endl;
}
