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
    while (N % 3 == 0) {
        N /= 3;
    }
    while (N % 2 == 0) {
        N /= 2;
    }

    if (N == 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}