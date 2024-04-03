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

    vector<int> l(N + 1);
    for (int i = 0; i < N; i++) {
        l[i + 1] += A[i] + l[i];
        debug(l[i + 1]);
    }

    map<int, int> mp;
    rep(i, N + 1) mp[l[i]]++;

    int ans = 0;
    rep(i, N) {
        mp[l[i]]--;
        int seek = K + l[i];
        ans += mp[seek];
    }

    cout << ans << endl;
}
