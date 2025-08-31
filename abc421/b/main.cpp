#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int X, Y;
    cin >> X >> Y;

    vector<int> A(10);
    A[0] = X, A[1] = Y;

    for (int i = 2; i < 10; i++) {
        string s = to_string(A[i - 2] + A[i - 1]);
        reverse(all(s));
        A[i] = stoll(s);
    }
    cout << A[9] << endl;
}
