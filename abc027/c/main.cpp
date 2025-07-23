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

    int d = 1, t = 1;
    while (2 * t <= N) {
        t *= 2;
        d++;
    }
    debug(d);
    d++;

    int x = 1;
    for (int i = 0; i < 70; i++) {
        if (i % 2 == 0) {
            if (d % 2) {
                x = 2 * x;
            } else {
                x = 2 * x + 1;
            }
            if (x > N) {
                cout << "Aoki" << endl;
                return 0;
            }
        } else {
            if (d % 2) {
                x = 2 * x + 1;
            } else {
                x = 2 * x;
            }
            if (x > N) {
                cout << "Takahashi" << endl;
                return 0;
            }
        }
    }
}
