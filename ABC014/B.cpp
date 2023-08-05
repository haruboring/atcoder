#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int n, X;
    cin >> n >> X;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    int sum = 0;
    rep(i, n) {
        if (((1 << i) & X) != 0) {
            sum += a[i];
        }
    }
    cout << sum << endl;
}