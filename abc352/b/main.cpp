#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    string S, T;
    cin >> S >> T;

    int si = 0;
    rep(i, T.size()) {
        if (S[si] == T[i]) {
            si++;
            cout << i + 1 << " ";
            if (si == S.size()) {
                break;
            }
        }
    }
    cout << endl;
}
