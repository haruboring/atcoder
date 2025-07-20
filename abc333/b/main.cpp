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

    sort(all(S)), sort(all(T));

    if (((S[0] - S[1] + 5) % 5 == (T[0] - T[1] + 5) % 5) || ((S[0] - S[1] + 5) % 5 == 5 - (T[0] - T[1] + 5) % 5)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
