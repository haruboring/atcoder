#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    string s;
    cin >> s;

    map<char, int> mp;
    for (char c : s) {
        mp[c]++;
    }

    for (auto [k, v] : mp) {
        if (v == 1) {
            rep(i, s.size()) {
                if (s[i] == k) {
                    cout << i + 1 << endl;
                    return 0;
                }
            }
        }
    }
}
