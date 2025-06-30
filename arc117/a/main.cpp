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

    if (A == B) {
        rep(i, A) cout << i + 1 << " " << -i - 1 << " ";

        cout << endl;
        return 0;
    }

    if (A > B) {
        int p = 0;
        rep(i, A) {
            cout << i + 1 << " ";
            p += i + 1;
        }
        rep(i, B - 1) {
            cout << -i - 1 << " ";
            p -= i + 1;
        }
        cout << -p << endl;
        return 0;
    }

    if (A < B) {
        int m = 0;
        rep(i, B) {
            cout << -i - 1 << " ";
            m -= i + 1;
        }
        rep(i, A - 1) {
            cout << i + 1 << " ";
            m += i + 1;
        }
        cout << -m << endl;
        return 0;
    }
}
