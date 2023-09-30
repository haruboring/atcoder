#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;

    bool pre = true, suf = true;

    rep(i, N) {
        if (S[i] != T[i]) {
            pre = false;
            break;
        }
    }

    rep(i, N) {
        if (S[N - 1 - i] != T[M - 1 - i]) {
            suf = false;
            break;
        }
    }

    if (pre && suf)
        cout << 0 << endl;
    else if (pre)
        cout << 1 << endl;
    else if (suf)
        cout << 2 << endl;
    else
        cout << 3 << endl;
}