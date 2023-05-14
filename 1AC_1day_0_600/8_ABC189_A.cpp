#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    string C;
    cin >> C;
    bool b = true;
    rep(i, 2) {
        if (C[i] != C[i + 1]) {
            b = false;
        }
    }
    if (b) {
        cout << "Won" << endl;
    } else {
        cout << "Lost" << endl;
    }
}