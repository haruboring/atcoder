#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    string S, T;
    cin >> S >> T;
    int cnt = 0;
    rep(i, 3) {
        if (S[i] == T[i]) cnt++;
    }
    cout << cnt << endl;
}