#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<ll> A(N);
    rep(i, N) {
        cin >> A[i];
    }
    ll max_sum = 0;
    ll sub = 0;
    rep(i, M) {
        max_sum += (i + 1) * A[i];
        sub += A[i];
    }
    ll sum = max_sum;
    rep(i, N - M) {
        sum = sum - sub + M * A[M + i];
        max_sum = max(max_sum, sum);
        sub = sub - A[i] + A[M + i];
    }
    cout << max_sum << endl;
}