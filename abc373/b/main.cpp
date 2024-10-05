#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    string S;
    cin >> S;

    map<char, int> mp;
    rep(i, S.size()) mp[S[i]] = i;

    int ans = 0;
    int pos = mp['A'];
    for (char c = 'B'; c <= 'Z'; c++) {
        ans += abs(mp[c] - pos);
        pos = mp[c];
    }

    cout << ans << endl;
}
