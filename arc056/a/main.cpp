#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int A, B, K, L;
    cin >> A >> B >> K >> L;

    if (A * L <= B) {
        cout << A * K << endl;
        return 0;
    }

    cout << min(B * ((K + L - 1) / L), B * (K / L) + A * (K % L)) << endl;
}
