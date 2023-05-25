#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    vector<int> a(10);
    rep(i, 10) cin >> a[i];
    int k = 0;
    rep(_, 3) {
        k = a[k];
    }
    cout << k << endl;
}