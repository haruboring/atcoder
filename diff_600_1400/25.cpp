#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;

    int cnt = 0;

    repp(i, 1, sqrt(N) + 1) {
        if (N % i == 0) {
            ll a = i;
            ll b = N / i;
            if (b % 2 == 1) cnt++;
            if (a != b && a % 2 == 1) cnt++;
        }
    }

    cout << 2 * cnt << endl;
}