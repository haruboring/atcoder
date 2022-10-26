#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
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