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

    for (int i = S.size() - 1; i >= 0; i--) {
        char c = S[i];
        if (c == '6') {
            cout << '9';
        } else if (c == '9') {
            cout << '6';
        } else {
            cout << c;
        }
    }
    cout << endl;
}
