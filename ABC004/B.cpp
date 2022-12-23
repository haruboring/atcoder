#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    vector<vector<char>> c(4, vector<char>(4));
    rep(i, 4) {
        rep(j, 4) {
            cin >> c[i][j];
        }
    }
    rep(i, 4) {
        rep(j, 4) {
            cout << c[3-i][3-j] << " ";
        }
        cout << endl;
    }
}