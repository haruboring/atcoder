#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int A, B, X;
    cin >> A >> B >> X;
    if (A <= X && X <= A + B) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}