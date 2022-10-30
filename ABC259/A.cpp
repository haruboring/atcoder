#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, M, X, T, D;
    cin >> N >> M >> X >> T >> D;
    if (M >= X) {
        cout << T << endl;
    } else {
        cout << T - (X - M) * D << endl;
    }
}