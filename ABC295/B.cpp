#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int R, C;

void after_explosion(vector<string> &B, int i, int j, int power) {
    rep(a, R) {
        rep(b, C) {
            if (abs(a - i) + abs(b - j) <= power) {
                if ((!(a == i && b == j) && B[a][b] == '#') || (a == i && b == j)) {
                    B[a][b] = '.';
                }
            }
        }
    }
}

int main() {
    cin >> R >> C;
    vector<string> B(R);
    rep(i, R) {
        cin >> B[i];
    }
    rep(i, R) {
        rep(j, C) {
            if (B[i][j] != '.' && B[i][j] != '#') {
                after_explosion(B, i, j, B[i][j] - '0');
            }
        }
    }
    rep(i, R) {
        cout << B[i] << endl;
    }
}