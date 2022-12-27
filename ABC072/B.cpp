#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    string ans = "";
    rep(i, s.size()) {
        if (i % 2 == 0) {
            ans += s[i];
        }
    }
    cout << ans << endl;
}