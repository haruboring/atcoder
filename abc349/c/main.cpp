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

    if (T[2] == 'X') {
        int t_idx = 0;
        for (int i = 0; i < S.size(); i++) {
            if (t_idx < 2 && S[i] == T[t_idx] + 'a' - 'A') {
                t_idx++;
            }
        }

        if (t_idx == 2) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        return 0;
    }
    int t_idx = 0;
    for (int i = 0; i < S.size(); i++) {
        if (t_idx < 3 && S[i] == T[t_idx] + 'a' - 'A') {
            t_idx++;
        }
    }

    if (t_idx == 3) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
