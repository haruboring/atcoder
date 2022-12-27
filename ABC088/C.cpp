#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    vector<vector<int>> c(3, vector<int>(3));
    rep(i, 3) {
        rep(j, 3) {
            cin >> c[i][j];
        }
    }
    int a2, a3, b1, b2, b3;
    rep(a1, c[0][0] + 1) {
        b1 = a1 - c[0][0];
        a2 = c[1][0] - b1;
        a3 = c[2][0] - b1;
        b2 = c[0][1] - a1;
        b3 = c[0][2] - a1;
        if (c[1][1] == a2 + b2 && c[1][2] == a2 + b3 && c[2][1] == a3 + b2 && c[2][2] == a3 + b3) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}