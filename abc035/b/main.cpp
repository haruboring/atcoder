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
    int T;
    cin >> T;

    int x = 0, y = 0, cnt = 0;
    for (char c : S) {
        if (c == 'U') {
            y++;
        } else if (c == 'D') {
            y--;
        } else if (c == 'L') {
            x++;
        } else if (c == 'R') {
            x--;
        } else {
            cnt++;
        }
    }

    x = abs(x), y = abs(y);

    if (T == 1) {
        cout << x + y + cnt << endl;
        return 0;
    }

    int d = x + y - cnt;
    if (d < 0) {
        d *= -1;
        d %= 2;
    }
    cout << d << endl;
}