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
    rep(i, N) cin >> A[i];

    vector<int> up(N), down(N);

    vector<int> B;
    for (int i = 0; i < N; i++) {
        auto it = lower_bound(all(B), A[i]);
        if (it == B.end()) {
            B.push_back(A[i]);
        } else {
            B[it - B.begin()] = A[i];
        }

        up[i] = B.size();
    }

    B.clear();
    for (int i = N - 1; i >= 0; i--) {
        auto it = lower_bound(all(B), A[i]);
        if (it == B.end()) {
            B.push_back(A[i]);
        } else {
            B[it - B.begin()] = A[i];
        }

        down[i] = B.size();
    }

    int ans = 0;
    rep(i, N - 1) {
        ans = max(ans, up[i] + down[i] - 1);
    }

    cout << ans << endl;
}
