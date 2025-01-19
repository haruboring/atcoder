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
    char c1, c2;
    cin >> N >> c1 >> c2;
    string S;
    cin >> S;

    rep(i, N) {
        if (S[i] != c1) {
            cout << c2;
        } else {
            cout << c1;
        }
    }
    cout << endl;
}
