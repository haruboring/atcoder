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
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    vector<int> mod = {1000000007, 1000000009, 998244353};
    vector<vector<int>> A(N, vector<int>(3));
    rep(i, N) {
        rep(k, 3) {
            rep(j, S[i].size()) {
                A[i][k] = (A[i][k] * 10 + S[i][j] - '0') % mod[k];
            }
        }
    }
    map<tuple<int, int, int>, int> mp;
    rep(i, N) {
        mp[{A[i][0] % mod[0], A[i][1] % mod[1], A[i][2] % mod[2]}]++;
    }

    int ans = 0;
    rep(i, N) {
        rep(j, N) {
            ans += mp[{A[i][0] * A[j][0] % mod[0], A[i][1] * A[j][1] % mod[1], A[i][2] * A[j][2] % mod[2]}];
        }
    }

    cout << ans << endl;
}
