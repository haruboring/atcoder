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
    rep(i, 10) {
        bool used = false;
        rep(j, 9) {
            if (S[j] == char(i + '0')) {
                used = true;
            }
        }
        if (used == false) {
            cout << i << endl;
            return 0;
        }
    }
}