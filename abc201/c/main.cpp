#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    string S;
    cin >> S;

    int cnt = 0;
    for (int i = 0; i < pow(5, 10); i++) {
        vector<int> t(10);
        int ci = i;
        rep(j, 10) {
            t[j] = ci % 5;
            ci /= 5;
        }

        int tt = 0;
        bool ok = true;
        rep(j, 10) {
            tt += t[j];
            if (S[j] == 'o' && t[j] == 0) ok = false;
            if (S[j] == 'x' && t[j] > 0) ok = false;
        }
        if (tt != 4) ok = false;

        if (!ok) continue;

        int tmp = 4 * 3 * 2 * 1;
        rep(j, 10) {
            repp(k, 1, t[j] + 1) {
                tmp /= k;
            }
        }

        cnt += tmp;
    }

    cout << cnt << endl;
}
