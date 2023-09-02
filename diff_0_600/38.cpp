#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;

    int cnt = 0;
    for (char c : S) {
        if (c == 'o') cnt++;
    }
    if (cnt + (15 - S.size()) > 7) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}