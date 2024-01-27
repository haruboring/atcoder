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

    if (!isupper(S[0])) {
        cout << "No" << endl;
        return 0;
    }
    rep(i, S.size() - 1) {
        if (isupper(S[i + 1])) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}
