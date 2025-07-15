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

    set<char> s;
    map<char, int> m;
    rep(i, 4) {
        s.insert(S[i]);
        m[S[i]]++;
    }

    if (s.size() != 2) {
        cout << "No" << endl;
        return 0;
    }
    for (auto [k, v] : m) {
        if (v != 2) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}
