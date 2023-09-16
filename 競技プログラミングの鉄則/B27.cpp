#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    ll A, B, cA, cB;
    cin >> A >> B;
    cA = A;
    cB = B;
    while (min(A, B) != 0) {
        if (A < B) {
            B = B % A;
        } else {
            A = A % B;
        }
    }
    ll gcd = max(A, B);
    cout << (cA / gcd) * (cB / gcd) * gcd << endl;
}