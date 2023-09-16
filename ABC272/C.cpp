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
    vector<int> A(N);
    rep(i, N) {
        cin >> A[i];
    }
    sort(all(A));
    int even_even = -1, first_even = -1, odd_odd = -1, first_odd = -1;
    rep(i, N) {
        if (A[i] % 2 == 0 && first_even == -1) {
            first_even = A[i];
        } else if (A[i] % 2 == 0) {
            even_even = first_even + A[i];
            first_even = A[i];
        } else if (A[i] % 2 == 1 && first_odd == -1) {
            first_odd = A[i];
        } else {
            odd_odd = first_odd + A[i];
            first_odd = A[i];
        }
    }
    cout << max(even_even, odd_odd) << endl;
}