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
    vector<string> S(N), T(N);
    rep(i, N) cin >> S[i] >> T[i];

    map<string, int> m;
    rep(i, N) {
        m[S[i]]++;
        m[T[i]]++;
    }

    rep(i, N) {
        if (S[i] == T[i]) {
            if (m[S[i]] > 2) {
                cout << "No" << endl;
                return 0;
            }
        } else {
            if (m[S[i]] > 1 && m[T[i]] > 1) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}
