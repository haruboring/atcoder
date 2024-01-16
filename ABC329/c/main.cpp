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
    string S;
    cin >> S;

    map<char, int> mp;
    int rp = 0;
    rep(i, N) {
        if (i == 0)
            rp++;
        else if (S[i] == S[i - 1]) {
            rp++;
        } else {
            mp[S[i - 1]] = max(mp[S[i - 1]], rp);
            rp = 1;
        }

        if (i == N - 1) mp[S[i]] = max(mp[S[i]], rp);
    }

    int ans = 0;
    for (auto [a, cnt] : mp) {
        ans += cnt;
    }

    cout << ans << endl;
}
