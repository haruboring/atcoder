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
    }
    int mid = N / 2, left = 0, right = N - 1;
    while (left != right) {
        if (A[mid] < X) {
            left = mid + 1;
            mid = (left + right) / 2;
        } else if (A[mid] == X) {
            cout << mid + 1 << endl;
            return 0;
        } else {
            right = mid - 1;
            mid = (left + right) / 2;
        }
    }

    cout << left + 1 << endl;
}