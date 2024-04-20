#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    bool a = false;
    rep(i, N) {
        if (S[i] == 'x') {
            cout << "No" << endl;
            return 0;
        } else if (S[i] == 'o') {
            a = true;
        }
    }
    if (a) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}