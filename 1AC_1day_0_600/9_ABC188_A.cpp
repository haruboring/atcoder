#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int X, Y;
    cin >> X >> Y;
    if (abs(X - Y) < 3) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}