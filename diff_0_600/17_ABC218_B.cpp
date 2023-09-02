#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    vector<int> P(26);
    rep(i, 26) cin >> P[i];
    rep(i, 26) cout << char('a' + P[i] - 1);
    cout << endl;
}