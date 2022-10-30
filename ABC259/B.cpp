#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    double a, b, d;
    cin >> a >> b >> d;
    double length = sqrt(a * a + b * b);
    if (length == 0) {
        cout << fixed << setprecision(20) << double(0) << " " << double(0) << endl;
        return 0;
    }
    double theta = atan2(b, a);
    double theta_plus_alpha = theta + M_PI * (d / 180);
    cout << fixed << setprecision(20) << length * cos(theta_plus_alpha) << " " << length * sin(theta_plus_alpha) << endl;
}