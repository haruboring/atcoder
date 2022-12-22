#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;
    rep(i, T) {
        ll a, s;
        cin >> a >> s;
        bool b = false;
        if (s - 2 * a >= 0) {
            if (((s - 2 * a) & a) == 0) {
                b = true;
            }
        }
        if (b) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}