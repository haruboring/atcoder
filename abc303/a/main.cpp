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
    string S, T;
    cin >> S >> T;

    rep(i, N) {
        char x = S[i], y = T[i];
        if (x == y) continue;
        if ((x == '1' && y == 'l') || (x == 'l' && y == '1')) continue;
        if ((x == '0' && y == 'o') || (x == 'o' && y == '0')) continue;

        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
}
