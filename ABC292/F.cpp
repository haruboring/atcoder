#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    double A, B;
    cin >> A >> B;

    // A<=B
    if (A > B) swap(A, B);

    if (3 * B * B >= 4 * A * A) {
        cout << setprecision(20) << 2 * A / sqrt(3) << endl;
        return 0;
    }
    cout << setprecision(20) << B / cos(atan(2 * A / B - sqrt(3))) << endl;
}