#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;

    int cnt = 0;
    int fi = 0, ri = s.size() - 1;
    while (fi < ri) {
        if (s[fi] == s[ri]) {
            fi++;
            ri--;
        } else if (s[fi] == 'x') {
            fi++;
            cnt++;
        } else if (s[ri] == 'x') {
            ri--;
            cnt++;
        } else {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << cnt << endl;
}