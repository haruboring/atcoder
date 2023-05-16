#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<double> A(N), B(N);
    rep(i, N) {
        cin >> A[i] >> B[i];
    }
    sort(all(A));
    sort(all(B));
    double min_med, max_med;
    if (N % 2 == 1) {
        min_med = A[(N + 1) / 2 - 1];
        max_med = B[(N + 1) / 2 - 1];
        cout << int(max_med - min_med + 1) << endl;
    } else {
        min_med = (A[N / 2 - 1] + A[N / 2]) / 2;
        max_med = (B[N / 2 - 1] + B[N / 2]) / 2;
        cout << int(2 * (max_med - min_med) + 1) << endl;
    }
}