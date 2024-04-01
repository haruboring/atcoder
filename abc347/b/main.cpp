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
    set<string> ss;
    rep(i, S.size()) {
        repp(j, i, S.size()) {
            ss.insert(S.substr(i, j - i + 1));
        }
    }

    if (ss.count("")) {
        ss.erase("");
    }

    cout << ss.size() << endl;
}
