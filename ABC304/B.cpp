#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;

    if (S.size() < 3) {
        cout << S << endl;
        return 0;
    }
    rep(i, 3) {
        cout << S[i];
    }
    rep(i, S.size() - 3) {
        cout << '0';
    }
    cout << endl;
}