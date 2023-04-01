#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    vector<string> S(8);
    rep(i, 8) {
        cin >> S[i];
    }
    rep(i, 8) {
        rep(j, 8) {
            if (S[i][j] == '*') {
                cout << char('a' + j) << 8 - i << endl;
                return 0;
            }
        }
    }
}