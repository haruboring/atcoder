#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    double A, B;
    cin >> A >> B;
    double length = sqrt(A * A + B * B);
    cout << fixed << setprecision(10) << A / length << " " << B / length << endl;
}