#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, K, M;
    cin >> N >> K >> M;
    vector<int> A(N - 1);
    rep(i, N - 1) cin >> A[i];

    int sum = accumulate(all(A), 0);
    int ans = max(0, M * N - sum);
    if (ans > K) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}