#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    rep(i, N) {
        cin >> A[i];
        A[i] -= (i % 2 == 1);
    }

    int sum = accumulate(all(A), 0);
    if (sum <= X) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
