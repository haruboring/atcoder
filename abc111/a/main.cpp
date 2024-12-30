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

    for (char c : S) {
        if (c == '1') {
            cout << '9';
        } else if (c == '9') {
            cout << '1';
        } else {
            cout << c;
        }
    }
    cout << endl;
}
