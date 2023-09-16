#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    string X;
    cin >> X;
    while (X.size()) {
        if (X[0] == 'o' || X[0] == 'k' || X[0] == 'u') {
            X.erase(0, 1);
        } else if (X[0] == 'c' && X[1] == 'h') {
            X.erase(0, 2);
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}