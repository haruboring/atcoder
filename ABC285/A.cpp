#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int a, b;
    cin >> a >> b;
    if (2 * a == b || 2 * a + 1 == b) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}