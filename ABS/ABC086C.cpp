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
    vector<string> der(4);
    der[0] = "dreamer", der[1] = "dream", der[2] = "eraser", der[3] = "erase";
    while (S.size()) {
        rep(i, 5) {
            if (i == 4) {
                cout << "NO" << endl;
                return 0;
            }
            if (equal(all(der[i]), S.begin())) {
                if (i == 0) {
                    if (S[der[0].size()] == 'a') {
                        continue;
                    }
                }
                S.erase(0, der[i].size());
                break;
            }
        }
    }
    cout << "YES" << endl;
}