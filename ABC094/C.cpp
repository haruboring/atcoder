#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> X(N), cX(N);
    rep(i, N) {
        cin >> X[i];
    }
    cX = X;
    sort(all(X));
    int r = X[N / 2], l = X[N / 2 - 1];
    rep(i, N) {
        if (cX[i] < r) {
            cout << r << endl;
        } else {
            cout << l << endl;
        }
    }
}