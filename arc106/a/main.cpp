#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N;
    cin >> N;

    repp(a, 1, 100) {
        repp(b, 1, 100) {
            if (powl(3, a) + powl(5, b) == N) {
                cout << a << " " << b << endl;
                return 0;
            }
            if (powl(5, b) > N / 5) break;
        }
        if (powl(3, a) > N / 3) break;
    }

    cout << -1 << endl;
}
