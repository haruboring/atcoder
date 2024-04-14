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

    map<int, set<char>> mp;
    for (char c = 'a'; c <= 'z'; c++) {
        int cnt = 0;
        rep(i, S.size()) {
            if (S[i] == c) cnt++;
        }

        if (cnt > 0) {
            mp[cnt].insert(c);
        }
    }

    for (auto a : mp) {
        if (a.second.size() == 0 || a.second.size() == 2) {
            continue;
        } else {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}
