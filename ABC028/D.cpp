#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    double N, K;
    cin >> N >> K;
    cout << fixed << setprecision(15) << (6 * (K - 1) * (N - K) + 3 * (N - K) + 3 * (K - 1) + 1) / pow(N, 3) << endl;
}