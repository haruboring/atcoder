#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int a, b;
    cin >> a >> b;

    if (a + b == 15) {
        cout << "+" << endl;
    } else if (a * b == 15) {
        cout << "*" << endl;
    } else {
        cout << "x" << endl;
    }
}
