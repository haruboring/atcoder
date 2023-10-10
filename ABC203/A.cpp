#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    vector<int> s(3);
    rep(i, 3) cin >> s[i];

    sort(all(s));

    if (s[0] == s[1]) {
        cout << s[2] << endl;
    } else if (s[1] == s[2]) {
        cout << s[0] << endl;
    } else {
        cout << 0 << endl;
    }
}