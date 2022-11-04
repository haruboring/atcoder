#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int A, B;
    cin >> A >> B;
    repp(i, A, B + 1) {
        if (100 % i == 0) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}