#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int L1, R1, L2, R2;
    cin >> L1 >> R1 >> L2 >> R2;
    cout << max(0, min(R1, R2) - max(L1, L2)) << endl;
}