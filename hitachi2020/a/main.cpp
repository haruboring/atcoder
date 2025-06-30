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

    if (S.size() % 2 != 0) {
        cout << "No" << endl;
        return 0;
    }

    for (int i = 0; i < S.size(); i += 2) {
        if ("hi" != S.substr(i, 2)) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}
