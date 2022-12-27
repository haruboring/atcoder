#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int A, B, X;
    cin >> A >> B >> X;
    if (A <= X && X <= A + B) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}