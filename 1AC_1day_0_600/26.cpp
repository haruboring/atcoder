#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    string S1, S2;
    cin >> S1 >> S2;

    int cnt = 0;
    rep(i, 2) {
        if (S1[i] == '#') cnt++;
        if (S2[i] == '#') cnt++;
    }

    if (cnt == 2 && S1[0] == S2[1]) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
}