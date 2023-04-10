#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    ll A, B;
    cin >> A >> B;
    ll ans = 0;
    while (A != B) {
        if (A > B) {
            if (B == 0) {
                A = 0;
                ans++;
            } else {
                ans += A / B;
                A -= B * (A / B);
                if (A % B == 0) {
                    A -= B * (A / B - 1);
                    ans--;
                }
            }
        } else {
            if (A == 0) {
                B = 0;
                ans++;
            } else {
                ans += B / A;
                B -= A * (B / A);
                if (B % A == 0) {
                    B -= A * (B / A - 1);
                    ans--;
                }
            }
        }
    }
    cout << ans << endl;
}