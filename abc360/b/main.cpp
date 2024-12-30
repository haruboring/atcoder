#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    string S, T;
    cin >> S >> T;

    repp(c, 1, S.size()) {
        repp(w, c, S.size() + 1) {
            string tmp = "";
            rep(i, (S.size() + w - 1) / w) {
                if (i * w + c > S.size()) continue;
                tmp += S[i * w + c - 1];
            }

            if (tmp == T) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
}
