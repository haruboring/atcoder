#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

double f(double x) {
    return pow(x, 3) + x;
}

int main() {
    double N;
    cin >> N;
    double L = 0, R = 100, M;
    while (1) {
        M = (L + R) / 2;
        if (abs(f(M) - N) < 0.001) {
            cout << fixed << setprecision(10) << M << endl;
            return 0;
        } else if (f(M) > N) {
            R = M;
        } else {
            L = M;
        }
    }
}