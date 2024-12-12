#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int A, K;
    cin >> A >> K;

    if (K == 0) {
        cout << 2000000000000 - A << endl;
        return 0;
    }

    int nityo = 2000000000000;
    int days = 0;
    while (A < nityo) {
        A += 1 + K * A;
        days++;
    }

    cout << days << endl;
}
