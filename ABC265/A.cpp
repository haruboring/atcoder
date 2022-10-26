#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int X, Y, N;
    cin >> X >> Y >> N;
    int ans = Y * (N / 3) + X * (N % 3);
    ans = min(ans, X * N);
    cout << ans << endl;
}