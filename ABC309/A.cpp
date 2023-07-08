#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int A, B;
    cin >> A >> B;
    if (A + 1 == B) {
        if (A == 3 || A == 6 || A == 9) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    } else {
        cout << "No" << endl;
    }
}