#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    rep(i, H) {
        rep(j, W) {
            cin >> A[i][j];
        }
    }
    rep(i, H) {
        rep(j, W) {
            if (A[i][j] == 0) {
                cout << ".";
            } else {
                cout << char('A' + A[i][j] - 1);
            }
        }
        cout << endl;
    }
}