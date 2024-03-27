#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    if (r1 == r2 && c1 == c2) {
        cout << 0 << endl;
        return 0;
    }

    if (r1 + c1 == r2 + c2 || r1 - c1 == r2 - c2 || abs(r1 - r2) + abs(c1 - c2) <= 3) {
        cout << 1 << endl;
        return 0;
    }

    if ((r1 + c1) % 2 == (r2 + c2) % 2 || abs(r1 - r2) + abs(c1 - c2) <= 6 || abs((r1 + c1) - (r2 + c2)) <= 3 || abs((r1 - c1) - (r2 - c2)) <= 3) {
        cout << 2 << endl;
        return 0;
    }

    cout << 3 << endl;
}