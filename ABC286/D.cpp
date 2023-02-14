#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

vector<bool> can_exactly_pay(10000 + 100, false);

void calculate_exacty_pay(int yn) {
    for (int i = 10000 + 100; i >= 0; i--) {
        if (can_exactly_pay[i]) {
            if (i + yn < 10000 + 10) {
                can_exactly_pay[i + yn] = true;
            }
        }
    }
}
int main() {
    int N, X;
    cin >> N >> X;
    vector<int> A(N), B(N);
    rep(i, N) {
        cin >> A[i] >> B[i];
    }
    can_exactly_pay[0] = true;
    rep(i, N) {
        rep(j, B[i]) {
            calculate_exacty_pay(A[i]);
        }
    }

    if (can_exactly_pay[X]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}