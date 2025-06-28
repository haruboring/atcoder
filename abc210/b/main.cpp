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

    rep(i, N) {
        if (S[i] == '0') continue;
        if (i % 2 == 0) {
            cout << "Takahashi" << endl;
        } else {
            cout << "Aoki" << endl;
        }
        return 0;
    }
}
