#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int finab[1000000 + 10];

int main() {
    int n;
    cin >> n;
    finab[3] = 1;
    rep(i, n - 3) {
        finab[i + 4] = (finab[i + 3] + finab[i + 2] + finab[i + 1]) % 10007;
    }
    cout << finab[n] << endl;
}