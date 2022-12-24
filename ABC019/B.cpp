#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    char c = s[0];
    int cnt = 0;
    rep(i, s.size()) {
        if (i == (int)s.size() - 1) {
            if (s[i] == c) {
                cout << c << cnt + 1;
            } else {
                cout << c << cnt << s[i] << 1;
            }
        } else if (s[i] != c) {
            cout << c << cnt;
            cnt = 1;
            c = s[i];
        } else {
            cnt++;
        }
    }
    cout << endl;
}