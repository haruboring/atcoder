#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    string S, T;
    cin >> S >> T;
    rep(i, T.size() + 1) {
        rep(j, T.size() + 1) {
            if (j == int(T.size())) {
                cout << "Yes" << endl;
                break;
            }
            if (S[(S.size() - T.size() + i + j) % S.size()] != '?' && T[j] != '?') {
                if (S[(S.size() - T.size() + i + j) % S.size()] != T[j]) {
                    cout << "No" << endl;
                    break;
                }
            }
        }
    }
}