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

    int ans = 1e18;
    map<int, int> mp;
    rep(i, M) mp[A[i]]++;

    rep(i, N + 10) {
        if (mp[i] == 0) {
            ans = i;
            break;
        }
    }

    rep(i, N - M) {
        bool ab = false;
        mp[A[i]]--;
        if (mp[A[i]] == 0 && A[i] < ans) ab = true;

        mp[A[i + M]]++;
        if (A[i] != A[i + M] && ab) ans = A[i];
    }

    cout << ans << endl;
}
