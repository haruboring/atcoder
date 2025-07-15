#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int A, B;
    cin >> A >> B;

    if (abs(A - B) % 2 == 1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    cout << (A + B) / 2 << endl;
}
