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
    string S;
    cin >> S;

    int t = 1;
    rep(i, N - 1) {
        if (S[i] == S[i + 1]) {
            t++;
        } else {
            t = 1;
        }

        if (t >= 3) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
