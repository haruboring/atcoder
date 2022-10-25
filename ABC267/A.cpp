#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    if (S[0] == 'M') {
        cout << 5 << endl;
    } else if (S[0] == 'T' && S[1] == 'u') {
        cout << 4 << endl;
    } else if (S[0] == 'W') {
        cout << 3 << endl;
    } else if (S[0] == 'T') {
        cout << 2 << endl;
    } else {
        cout << 1 << endl;
    }
}