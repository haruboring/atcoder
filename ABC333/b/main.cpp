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

    if ((S[1] - S[0] + 5) % 5 == 3 || (S[1] - S[0] + 5) % 5 == 2) {
        if ((T[1] - T[0] + 5) % 5 == 3 || (T[1] - T[0] + 5) % 5 == 2) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    if ((S[1] - S[0] + 5) % 5 == 1 || (S[1] - S[0] + 5) % 5 == 4) {
        if ((T[1] - T[0] + 5) % 5 == 1 || (T[1] - T[0] + 5) % 5 == 4) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
}
