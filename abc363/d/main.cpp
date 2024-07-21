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

    if (N <= 10) {
        cout << N - 1 << endl;
        return 0;
    }
    N -= 10;
    if (N <= 9) {
        cout << N << N << endl;
        return 0;
    }
    N -= 9;

    int b = 90;
    int base = 10;
    rep(_, 1000000) {
        if (N <= b) {
            string s = to_string(base + N - 1);
            cout << s;
            reverse(all(s));
            cout << s.substr(1, s.size() - 1) << endl;
            return 0;
        }
        N -= b;

        if (N <= b) {
            string s = to_string(base + N - 1);
            cout << s;
            reverse(all(s));
            cout << s << endl;
            return 0;
        }
        N -= b;

        b *= 10LL;
        base *= 10LL;
    }
}
