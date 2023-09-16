#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, A, B;
    cin >> N >> A >> B;
    rep(i, N * A) {
        rep(j, N * B) {
            if ((j / B) % 2 == (i / A) % 2) {
                cout << '.';
            } else {
                cout << '#';
            }
        }
        cout << endl;
    }
}