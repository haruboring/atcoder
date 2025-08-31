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

    int mod = 1000000007;
    vector<int> A(N);
    A[0] = 1, A[1] = 1;
    repp(i, 2, N) {
        A[i] = A[i - 1] + A[i - 2];
        A[i] %= mod;
    }
    cout << A[N - 1] << endl;
}
