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

    if (N % 2 == 0) {
        rep(i, N / 2 - 1) cout << '-';
        cout << "==";
        rep(i, N / 2 - 1) cout << '-';
    } else {
        rep(i, N / 2) cout << '-';
        cout << "=";
        rep(i, N / 2) cout << '-';
    }
    cout << endl;
}
