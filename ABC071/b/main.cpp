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

    for (char c = 'a'; c <= 'z'; c++) {
        bool ok = false;
        rep(i, S.size()) {
            if (S[i] == c) {
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << c << endl;
            return 0;
        }
    }

    cout << "None" << endl;
}
