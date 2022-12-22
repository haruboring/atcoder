#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    double A, B, C, X;
    cin >> A >> B >> C >> X;
    if (X <= A) {
        cout << 1 << endl;
    } else if (X <= B) {
        cout << fixed << setprecision(10) << C / (B - A) << endl;
    } else {
        cout << 0 << endl;
    }
}