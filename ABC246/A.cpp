#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    vector<int> a(6);
    map<int, int> x, y;
    rep(i, 6) {
        cin >> a[i];
        if (i % 2 == 0) {
            x[a[i]]++;
        } else {
            y[a[i]]++;
        }
    }
    rep(i, 3) {
        if (x[a[i * 2]] == 1) {
            cout << a[i * 2] << " ";
        }
    }
    rep(i, 3) {
        if (y[a[i * 2 + 1]] == 1) {
            cout << a[i * 2 + 1] << endl;
        }
    }
}