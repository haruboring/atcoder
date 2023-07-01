#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    sort(all(A));
    vector<int> B(N);
    rep(i, N / 2 + 1) {
        B[i * 2] = A[i];
    }
    rep(i, N / 2) {
        B[i * 2 + 1] = A[i + N / 2 + 1];
    }

    for (int i = 1; i < N; i += 2) {
        if (B[i - 1] >= B[i] || B[i] <= B[i + 1]) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}