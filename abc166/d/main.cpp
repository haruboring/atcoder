#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int X;
    cin >> X;

    repp(a, -200, 200) {
        repp(b, -200, 200) {
            if (pow(a, 5) - pow(b, 5) == X) {
                cout << a << " " << b << endl;
                return 0;
            }
        }
    }
}
