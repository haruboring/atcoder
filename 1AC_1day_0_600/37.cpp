#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int r, g, b;
    cin >> r >> g >> b;
    int num = 100 * r + 10 * g + b;

    cout << (num % 4 == 0 ? "YES" : "NO") << endl;
}