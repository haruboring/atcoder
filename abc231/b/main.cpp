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
    map<string, int> mp;
    rep(i, N) {
        string s;
        cin >> s;
        mp[s]++;
    }

    int max = -1;
    string ans = "";
    for (auto [k, v] : mp) {
        if (v > max) {
            max = v;
            ans = k;
        }
    }

    cout << ans << endl;
}
