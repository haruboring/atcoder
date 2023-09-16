#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int R, C;
    cin >> R >> C;
    if ((C <= R && R <= 16 - C) || (C >= R && R >= 16 - C)) {
        if (C % 2 == 1) {
            cout << "black" << endl;
        } else {
            cout << "white" << endl;
        }
    } else {
        if (R % 2 == 1) {
            cout << "black" << endl;
        } else {
            cout << "white" << endl;
        }
    }
}