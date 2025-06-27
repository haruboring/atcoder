#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int P;
    cin >> P;

    vector<int> A(0);
    int a = 1, b = 2;
    while (a <= P) {
        A.push_back(a);
        a *= b;
        b++;
    }

    reverse(all(A));
    int cnt = 0, idx = 0;
    while (P > 0) {
        if (P >= A[idx]) {
            P -= A[idx];
            cnt++;
        } else {
            idx++;
        }
    }

    cout << cnt << endl;
}
