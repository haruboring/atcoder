#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int T;
    cin >> T;
    vector<int> test(T);
    rep(i, T) {
        cin >> test[i];
    }
    rep(i, T) {
        int q, p;
        for (int a = 2; a < 3 * 1000000 + 100; a++) {
            if (test[i] % a == 0) {
                test[i] /= a;
                if (test[i] % a == 0) {
                    p = a;
                    q = test[i] / a;
                } else {
                    q = a;
                    p = (int)sqrt(test[i]);
                }
                break;
            }
        }
        cout << p << " " << q << endl;
    }
}