#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, L, R;
    cin >> N >> L >> R;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    rep(i, N) {
        if (L <= A[i] && A[i] <= R)
            cout << A[i] << " ";
        else if (A[i] < L)
            cout << L << " ";
        else
            cout << R << " ";
    }
    cout << endl;
}
