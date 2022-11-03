#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    rep(i, 10) {
        bool used = false;
        rep(j, 9) {
            if (S[j] == char(i + '0')) {
                used = true;
            }
        }
        if (used == false) {
            cout << i << endl;
            return 0;
        }
    }
}