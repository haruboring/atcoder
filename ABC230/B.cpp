#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    int x_cnt = 0;
    bool first_o = true, substring = true;
    rep(i, S.size()) {
        if (S[i] == 'x') {
            x_cnt++;
            if (x_cnt > 2) {
                substring = false;
            }
        } else {
            if (first_o) {
                first_o = false;
                if (x_cnt > 2) {
                    substring = false;
                }
            } else {
                if (x_cnt != 2) {
                    substring = false;
                }
            }
            x_cnt = 0;
        }
    }
    if (substring) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}