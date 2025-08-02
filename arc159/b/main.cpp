#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int gcd(int a, int b) {
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

signed main() {
    int A, B;
    cin >> A >> B;

    if (A > B) swap(A, B);
    int D = B - A;
    vector<int> P;
    for (int i = 2; i * i <= D; i++) {
        if (D % i) continue;
        while (D % i == 0) D /= i;
        P.push_back(i);
    }
    if (D > 1) P.push_back(D);
    int cnt = 0;
    while (A > 0 && B > 0) {
        int g = gcd(A, B);
        A /= g, B /= g;
        int k = A;
        for (int p : P) {
            if ((B - A) % p) continue;
            k = min(k, A % p);
        }
        cnt += k;
        A -= k, B -= k;
    }

    cout << cnt << endl;
}
