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

    string z = "1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
    cout << "3.";
    rep(i, N) cout << z[i];
    cout << endl;
}
