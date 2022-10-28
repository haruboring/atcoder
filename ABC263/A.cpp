#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    vector<int> A_E(5);
    rep(i, 5) {
        cin >> A_E[i];
    }
    sort(all(A_E));
    if (A_E[0] == A_E[1] && A_E[1] == A_E[2] && A_E[2] != A_E[3] && A_E[3] == A_E[4]) {
        cout << "Yes" << endl;
    } else if (A_E[0] == A_E[1] && A_E[1] != A_E[2] && A_E[2] == A_E[3] && A_E[3] == A_E[4]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}