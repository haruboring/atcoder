#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    if (A - B == A + B && A - B == C) {
        cout << "?" << endl;
    } else if (A + B == C) {
        cout << "+" << endl;
    } else if (A - B == C) {
        cout << "-" << endl;
    } else {
        cout << "!" << endl;
    }
}