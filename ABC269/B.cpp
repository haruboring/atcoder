#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    vector<string> S(10);
    rep(i, 10) {
        cin >> S.at(i);
    }
    int A = 0, B = 0, C = 0, D = 0;
    rep(i, 10) {
        rep(j, 10) {
            if (A == 0 && S[i][j] == '#') {
                A = i + 1;
                C = j + 1;
            }
            if (S[i][j] == '#') {
                B = i + 1;
                D = j + 1;
            }
        }
    }
    cout << A << " " << B << endl;
    cout << C << " " << D << endl;
}