#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int K;
    cin >> K;
    string S, T;
    cin >> S >> T;

    if (S == T) {
        cout << "Yes" << endl;
        return 0;
    }

    if (S.size() == T.size()) {
        int cnt = 0;
        rep(i, S.size()) {
            if (S[i] != T[i]) cnt++;
        }
        if (cnt == 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }

        return 0;

    } else if (S.size() + 1 == T.size()) {
        int cnt = 0;
        int j = 0;
        rep(i, T.size()) {
            if (S[j] != T[i]) {
                cnt++;
                if (cnt > 2) {
                    cout << "No" << endl;
                    return 0;
                }
            } else {
                j++;
            }
        }

        if (cnt == 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }

        return 0;
    }

    else if (S.size() == T.size() + 1) {
        int cnt = 0;
        int j = 0;
        rep(i, S.size()) {
            if (S[i] != T[j]) {
                cnt++;
            } else {
                j++;
            }
        }

        if (cnt == 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }

        return 0;
    }

    else {
        cout << "No" << endl;
        return 0;
    }
}
